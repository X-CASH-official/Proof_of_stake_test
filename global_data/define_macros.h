#ifndef DEFINE_MACROS_H_   /* Include guard */
#define DEFINE_MACROS_H_

/*
-----------------------------------------------------------------------------------------------------------
Using define statements instead of constants for increased efficiency
-----------------------------------------------------------------------------------------------------------
*/

#define SEND_DATA_PORT 8000 // The port that is used by all nodes to send and receive data
#define XCASH_WALLET_LENGTH 98 // The length of a XCA address
#define CONSENSUS_NODE_PUBLIC_ADDRESS "XCA" // The consensus nodes public address
#define CONSENSUS_BACKUP_NODE_PUBLIC_ADDRESS "XCA" // The consensus backup nodes public address
#define CONSENSUS_NODES_IP_ADDRESS "" // The consensus nodes IP address
#define CONSENSUS_BACKUP_NODES_IP_ADDRESS "" // The consensus backup nodes IP address
#define RANDOM_STRING_LENGTH 100 // The length of the random string

// lengths
#define BUFFER_SIZE 64000
#define BLOCKCHAIN_DATA_NETWORK_VERSION_DATA_SIZE 5 // The maximum size of the network_version_data
#define BLOCKCHAIN_DATA_TIMESTAMP_DATA_SIZE 11 // The maximum size of the timestamp_data
#define BLOCKCHAIN_DATA_PREVIOUS_BLOCK_HASH_DATA_SIZE 65 // The maximum size of the previous_block_hash_data
#define BLOCKCHAIN_DATA_NONCE_DATA_SIZE 9 // The maximum size of the nonce_data
#define BLOCKCHAIN_DATA_BLOCK_REWARD_TRANSACTION_VERSION_DATA_SIZE 3 // The maximum size of the block_reward_transaction_version_data
#define BLOCKCHAIN_DATA_UNLOCK_BLOCK_DATA_SIZE 9 // The maximum size of the unlock_block_data
#define BLOCKCHAIN_DATA_BLOCK_REWARD_INPUT_DATA_SIZE 3 // The maximum size of the block_reward_input_data
#define BLOCKCHAIN_DATA_VIN_TYPE_DATA_SIZE 3 // The maximum size of the vin_type_data
#define BLOCKCHAIN_DATA_BLOCK_HEIGHT_DATA_SIZE 9 // The maximum size of the block_height_data
#define BLOCKCHAIN_DATA_BLOCK_REWARD_OUTPUT_DATA_SIZE 3 // The maximum size of the block_reward_output_data
#define BLOCKCHAIN_DATA_BLOCK_REWARD_DATA_SIZE 15 // The maximum size of the block_reward_data
#define BLOCKCHAIN_DATA_STEALTH_ADDRESS_OUTPUT_TAG_DATA_SIZE 3 // The maximum size of the stealth_address_output_tag_data
#define BLOCKCHAIN_DATA_STEALTH_ADDRESS_OUTPUT_DATA_SIZE 65 // The maximum size of the stealth_address_output_data
#define BLOCKCHAIN_DATA_EXTRA_BYTES_SIZE_DATA_SIZE 5 // The maximum size of the extra_bytes_size_data
#define BLOCKCHAIN_DATA_TRANSACTION_PUBLIC_KEY_TAG_DATA_SIZE 3 // The maximum size of the transaction_public_key_tag_data
#define BLOCKCHAIN_DATA_TRANSACTION_PUBLIC_KEY_DATA_SIZE 65 // The maximum size of the transaction_public_key_data
#define BLOCKCHAIN_DATA_EXTRA_NONCE_TAG_DATA_SIZE 3 // The maximum size of the extra_nonce_tag_data
#define BLOCKCHAIN_DATA_RESERVE_BYTES_SIZE_DATA_SIZE 5 // The maximum size of the reserve_bytes_size_data
#define BLOCKCHAIN_DATA_BLOCKCHAIN_RESERVE_BYTES_BLOCK_PRODUCER_DELEGATES_NAME_DATA_SIZE 41 // The maximum size of the block_producer_delegates_name_data
#define BLOCKCHAIN_DATA_BLOCKCHAIN_RESERVE_BYTES_BLOCK_PRODUCER_DELEGATES_NAME_SIZE 21 // The maximum size of the block_producer_delegates_name
#define BLOCKCHAIN_DATA_BLOCKCHAIN_RESERVE_BYTES_BLOCK_PRODUCER_PUBLIC_ADDRESS_DATA_SIZE 197 // The maximum size of the block_producer_public_address_data
#define BLOCKCHAIN_DATA_BLOCKCHAIN_RESERVE_BYTES_BLOCK_PRODUCER_PUBLIC_ADDRESS_SIZE 99 // The maximum size of the block_producer_public_address
#define BLOCKCHAIN_DATA_BLOCKCHAIN_RESERVE_BYTES_BLOCK_PRODUCER_NODE_BACKUP_COUNT_DATA_SIZE 3 // The maximum size of the block_producer_node_backup_count_data
#define BLOCKCHAIN_DATA_BLOCKCHAIN_RESERVE_BYTES_BLOCK_PRODUCER_NODE_BACKUP_COUNT_SIZE 2 // The maximum size of the block_producer_node_backup_count
#define BLOCKCHAIN_DATA_BLOCKCHAIN_RESERVE_BYTES_BLOCK_PRODUCER_BACKUP_NODES_NAMES_DATA_SIZE 249 // The maximum size of the block_producer_backup_nodes_names_data
#define BLOCKCHAIN_DATA_BLOCKCHAIN_RESERVE_BYTES_BLOCK_PRODUCER_BACKUP_NODES_NAMES_SIZE 125 // The maximum size of the block_producer_backup_nodes_names
#define BLOCKCHAIN_DATA_BLOCKCHAIN_RESERVE_BYTES_BLOCK_VALIDATION_NODE_SIGNATURE_DATA_SIZE 196 // The maximum size of the block_validation_node_signature_data
#define BLOCKCHAIN_DATA_RINGCT_VERSION_DATA_SIZE 3 // The maximum size of the ringct_version_data
#define BLOCKCHAIN_DATA_TRANSACTION_AMOUNT_DATA 65 // The maximum size of the transaction_amount_data

// VRF
#define VRF_PUBLIC_KEY_LENGTH 64 // The size of the VRF public key data
#define VRF_SECRET_KEY_LENGTH 128 // The size of the VRF secret key data
#define VRF_PROOF_LENGTH 160 // The size of the VRF proof data
#define VRF_BETA_LENGTH 128 // The size of the VRF beta string data
#define VRF_DATA_LENGTH 8 // true when the VRF data is verified

#define NODES_UPDATED_TIME_FILE_NAME "nodes_updated_time.txt" // The last time the node has updated the list of nodes from the consensus node
#define NODES_PUBLIC_ADDRESS_LIST_FILE_NAME "nodes_public_address_list.txt" // The current enabled nodes public address list
#define NODES_NAME_LIST_FILE_NAME "nodes_name_list.txt" // The current enabled nodes name list
#define NETWORK_BLOCK_TIME 300 // The network block time for the network in seconds (5 minutes)
#define UPDATE_BLOCK_VERIFIERS_TIME 120 // The time it takes the consensus node to update all of the block verifiers (2 minutes)
#define NETWORK_VERSION "0000" // the network version
#define MINIMUM_RESERVE_BYTE_LENGTH "2110"  // The minimum amount of reserve bytes
#define MAXIMUM_RESERVE_BYTE_LENGTH "2384" // The maximum amount of reserve bytes
#define RESERVE_BYTE_START_STRING "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000" // The reserve bytes the block producer will create using the get block template
#define BLOCKCHAIN_RESERVED_BYTES_START "7c424c4f434b434841494e5f52455345525645445f42595445535f53544152547c"
#define BLOCKCHAIN_DATA_SEGMENT_STRING "7c424c4f434b434841494e5f444154415f5345474d454e545f535452494e477c"
#define BLOCKCHAIN_RESERVED_BYTES_END "7c424c4f434b434841494e5f52455345525645445f42595445535f454e447c"
#define BLOCK_PRODUCER_NETWORK_BLOCK_NONCE "00000000" // the network block nonce used when the block producer creates the block
#define CONSENSUS_NODE_NETWORK_BLOCK_NONCE "11111111" // the network block nonce used when the consensus node creates the block
#define RESERVE_PROOFS_LIST_MAXIMUM_AMOUNT 20000 // the maximum amount of reserve proofs (total_supply / xcash_proof_of_stake_minimum_amount)
#define XCASH_PROOF_OF_STAKE_MINIMUM_AMOUNT 5000000000000 // the minimum amount the reserve proof can be created for
#define BLOCK_VALIDATION_NODES_TOTAL_AMOUNT 100 // The total amount of block validation nodes
#define DATA_HASH_LENGTH 128 // The length of the SHA2-512 hash
#define BLOCK_VALIDATION_NODES_AMOUNT 100 // The amount of block validation nodes needed to make the network block valid
#define BLOCK_VERIFIERS_AMOUNT 100 // The amount of block verifiers in a round
#define BLOCK_VERIFIERS_VALID_AMOUNT 67 // The amount of block verifiers that need to vote true for the part of the round to be valid.
#define TRUSTED_BLOCK_VERIFIERS_TOTAL_AMOUNT 100 // The total amount of trusted block verifiers
#define TRUSTED_BLOCK_VERIFIERS_AMOUNT 100 // The amount of trusted block verifiers needed to make the vote valid
#define BLOCK_VERIFIERS_NAME_TOTAL_LENGTH 100 // The maximum length of the block verifiers name
#define BLOCK_VERIFIERS_IP_ADDRESS_TOTAL_LENGTH 100 // The maximum length of the block verifiers IP address
#define DATABASE_CONNECTION "mongodb://localhost:27017" // the database connection string
#define DATABASE_NAME "XCASH_PROOF_OF_STAKE" // The name of the database
#define DATABASE_ARRAY_COUNT 100 // The maximum amount of parsed item and value from the database
#define BLOCK_VERIFIERS_TOTAL_VOTE_TIME 60 // The total amount of time for the block verifiers to send their votes to the consensus node
#define TOTAL_CONNECTION_TIME_SETTINGS 10 // The total time a client is given to connect to the server and send data
#define INVALID_PARAMETERS_ERROR_MESSAGE \
"Parameters\n" \
"--test - Run the test to make sure the program is compatible with your system\n"
#endif