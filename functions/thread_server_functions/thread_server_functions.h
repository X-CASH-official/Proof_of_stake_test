#ifndef THREAD_SERVER_FUNCTIONS_H_   /* Include guard */
#define THREAD_SERVER_FUNCTIONS_H_

/*
-----------------------------------------------------------------------------------------------------------
Function prototypes
-----------------------------------------------------------------------------------------------------------
*/

void* total_connection_time_thread(void* parameters);
void* mainnode_timeout_thread(void* parameters);
void* receive_votes_from_nodes_timeout_thread();
void* check_if_consensus_node_is_offline_timer();
void* check_if_consensus_node_needs_to_add_a_block_to_the_network_timer();
void* update_block_verifiers_timer();
#endif