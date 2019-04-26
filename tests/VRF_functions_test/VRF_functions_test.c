#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "define_macro_functions.h"
#include "define_macros.h"
#include "structures.h"

#include "string_functions.h"
#include "convert.h"
#include "vrf.h"
#include "crypto_vrf.h"
#include "VRF_functions.h"

#include "define_macros_test.h"
#include "variables_test.h"
#include "VRF_functions_test.h"

/*
-----------------------------------------------------------------------------------------------------------
Functions
-----------------------------------------------------------------------------------------------------------
*/

/*
-----------------------------------------------------------------------------------------------------------
Name: VRF_test
Description: Test the VRF functions
Return: The number of passed VRF test
-----------------------------------------------------------------------------------------------------------
*/

int VRF_test()
{
  // Constants
  const unsigned char data[crypto_vrf_SEEDBYTES] = {0x4c,0xcd,0x08,0x9b,0x28,0xff,0x96,0xda,0x9d,0xb6,0xc3,0x46,0xec,0x11,0x4e,0x0f,0x5b,0x8a,0x31,0x9f,0x35,0xab,0xa6,0x24,0xda,0x8c,0xf6,0xed,0x4f,0xb8,0xa6,0xfb};
  const unsigned char public_key[crypto_vrf_PUBLICKEYBYTES] = {0x3d,0x40,0x17,0xc3,0xe8,0x43,0x89,0x5a,0x92,0xb7,0x0a,0xa7,0x4d,0x1b,0x7e,0xbc,0x9c,0x98,0x2c,0xcf,0x2e,0xc4,0x96,0x8c,0xc0,0xcd,0x55,0xf1,0x2a,0xf4,0x66,0x0c};
  const unsigned char proof[crypto_vrf_PROOFBYTES] = {0xae,0x5b,0x66,0xbd,0xf0,0x4b,0x4c,0x01,0x0b,0xfe,0x32,0xb2,0xfc,0x12,0x6e,0xad,0x21,0x07,0xb6,0x97,0x63,0x4f,0x6f,0x73,0x37,0xb9,0xbf,0xf8,0x78,0x5e,0xe1,0x11,0x20,0x00,0x95,0xec,0xe8,0x7d,0xde,0x4d,0xbe,0x87,0x34,0x3f,0x6d,0xf3,0xb1,0x07,0xd9,0x17,0x98,0xc8,0xa7,0xeb,0x12,0x45,0xd3,0xbb,0x9c,0x5a,0xaf,0xb0,0x93,0x35,0x8c,0x13,0xe6,0xae,0x11,0x11,0xa5,0x57,0x17,0xe8,0x95,0xfd,0x15,0xf9,0x9f,0x07};
  const unsigned char alpha_string[1] = {"\x72"};
  const unsigned char beta_string[crypto_vrf_OUTPUTBYTES] = {0x94,0xf4,0x48,0x7e,0x1b,0x2f,0xec,0x95,0x43,0x09,0xef,0x12,0x89,0xec,0xb2,0xe1,0x50,0x43,0xa2,0x46,0x1e,0xcc,0x7b,0x2a,0xe7,0xd4,0x47,0x06,0x07,0xef,0x82,0xeb,0x1c,0xfa,0x97,0xd8,0x49,0x91,0xfe,0x4a,0x7b,0xfd,0xfd,0x71,0x56,0x06,0xbc,0x27,0xe2,0x96,0x7a,0x6c,0x55,0x7c,0xfb,0x58,0x75,0x87,0x9b,0x67,0x17,0x40,0xb7,0xd8};

  // Variables
  unsigned char vrf_public_key[crypto_vrf_PUBLICKEYBYTES];
  unsigned char vrf_secret_key[crypto_vrf_SECRETKEYBYTES];
  unsigned char vrf_proof[crypto_vrf_PROOFBYTES];
  unsigned char vrf_beta[crypto_vrf_OUTPUTBYTES];

  // define macros
  #define VRF_TOTAL_TEST 7

  // reset the variables
  memset(&string1_test,0,sizeof(string1_test)); 
  memset(string2_test,0,strnlen(string2_test,BUFFER_SIZE)); 
  count_test = 0;

  // write the start test message
  color_print(TEST_OUTLINE,"blue");
  printf("\033[1;34mVRF test - Total test: %d\033[0m\n",VRF_TOTAL_TEST);
  color_print(TEST_OUTLINE,"blue");
  printf("\n");

  // run the test

  // create a random VRF public key and secret key
  memset(vrf_public_key,0,strnlen((char*)vrf_public_key,crypto_vrf_PUBLICKEYBYTES));
  memset(vrf_secret_key,0,strnlen((char*)vrf_secret_key,crypto_vrf_SECRETKEYBYTES));
  if (create_random_VRF_keys((unsigned char*)vrf_public_key,(unsigned char*)vrf_secret_key) == 1 && crypto_vrf_is_valid_key((const unsigned char*)vrf_public_key) == 1)
  {
    color_print("PASSED! Test for creating a random VRF public key and secret key","green");
  }
  else
  {
    color_print("FAILED! Test for creating a random VRF public key and secret key","red");
  }

  // test if the VRF public key is the correct public key for the test data
  crypto_vrf_keypair_from_seed((unsigned char*)vrf_public_key, (unsigned char*)vrf_secret_key, (const unsigned char*)data);
  if (memcmp(vrf_public_key,public_key,crypto_vrf_PUBLICKEYBYTES) == 0)
  {
    color_print("PASSED! Test for verifying the VRF public and secret key from the initialization data","green");
  }
  else
  {
    color_print("FAILED! Test for verifying the VRF public and secret key from the initialization data","red");
  }

  // create the VRF proof
  if (crypto_vrf_prove((unsigned char*)vrf_proof,(const unsigned char*)vrf_secret_key,alpha_string,1) == 0 && memcmp(vrf_proof,proof,crypto_vrf_PROOFBYTES) == 0)
  {
    color_print("PASSED! Test for creating the VRF proof","green");
  }
  else
  {
    color_print("FAILED! Test for creating the VRF proof","red");
  }

  // check if the VRF proof is the correct proof for the test data
  if (crypto_vrf_proof_to_hash((unsigned char*)vrf_beta,(const unsigned char*)vrf_proof) == 0)
  {
    color_print("PASSED! Test for verifying the VRF proof from the secret key and the alpha string","green");
  }
  else
  {
    color_print("FAILED! Test for verifying the VRF proof from the secret key and the alpha string","red");
  }

  // Create the beta string
  memset(vrf_beta,0,strnlen((char*)vrf_beta,0));
  if (crypto_vrf_proof_to_hash((unsigned char*)vrf_beta,(const unsigned char*)vrf_proof) == 0)
  {
    color_print("PASSED! Test for creating the VRF beta string","green");
  }
  else
  {
    color_print("FAILED! Test for creating the VRF beta string","red");
  }

  // check if the VRF beta string is the correct beta string for the test data
  if (memcmp(vrf_beta,beta_string,crypto_vrf_OUTPUTBYTES) == 0)
  {
    color_print("PASSED! Test for verifying the VRF beta string from the public key, proof and the alpha string","green");
  }
  else
  {
    color_print("FAILED! Test for verifying the VRF beta string from the public key, proof and the alpha string","red");
  }

  // check that the proof, beta string, public key and alpha string all correspond to each other
  if (crypto_vrf_verify((unsigned char*)vrf_beta,(const unsigned char*)vrf_public_key,(const unsigned char*)vrf_proof,alpha_string,1) == 0)
  {
    color_print("PASSED! Test for verifying the VRF proof, beta string, public key and alpha string","green");
  }
  else
  {
    color_print("FAILED! Test for verifying the VRF proof, beta string, public key and alpha string","red");
  }

  // write the end test message
  if (count_test == VRF_TOTAL_TEST)
  {
    printf("\n");
    color_print(TEST_OUTLINE,"green");
    printf("\033[1;32mVRF test - Passed test: %d, Failed test: 0\033[0m\n",VRF_TOTAL_TEST);
    color_print(TEST_OUTLINE,"green");
    printf("\n\n");
  }
  else
  {
    printf("\n");
    color_print(TEST_OUTLINE,"red");
    printf("\033[1;31mVRF test - Passed test: %d, Failed test: %d\033[0m\n",count_test,VRF_TOTAL_TEST-count_test);
    color_print(TEST_OUTLINE,"red");
    printf("\n\n");
  } 
  return count_test;

  #undef VRF_TOTAL_TEST
}