#ifndef NODEBASE_H

#include "repository.h"
#include "hash.h"
#include "originchain.h"
#include "ZigZagBoundWitnessSession.h"
#include "state.h"

typedef struct NodeBase NodeBase;

struct NodeBase {
  RepositoryProvider* blockRepository;
  HashProvider* hashingProvider;
  OriginChainNavigator* originChainNavigator;
  OriginChainState* state;
  ZigZagBoundWitnessSession* session;
  /*
  * Gets the choice of a catalog from another party.
  */
  uint (*getChoice)(NodeBase* self, uint catalog, uint8_t strict);
  /*
  * Adds a heuristic to be used when creating bound witnesses.
  */
  uint8_t (*addHeuristic)(NodeBase* self, uint key, XYObject* heuristic);
  /*
  * Removes a heuristic from the current heuristic pool.
  */
  uint8_t (*removeHeuristic)(NodeBase* self, uint key);
  /*
  * Self signs an origin block to the devices origin chain.
  */
  uint8_t (*selfSignOriginChain)(NodeBase* self, uint flag);
  /*
  * Gets all of the unsigned payloads for a given flag.
  */
  uint8_t (*getUnSignedPayloads)(NodeBase* self, uint bitFlag);
  /*
  * Gets all of the signed payloads for a given flag.
  */
  uint8_t (*getSignedPayloads)(NodeBase* self, uint bitFlag);
  /*
  * Call the listener for each block in a bound witness.
  */
  uint8_t (*notifyListeners)(NodeBase* self, ZigZagBoundWitness* boundWitness);
  /*
  * Get blocks to bridge
  */
  XYResult* (*getBridgedBlocks)(NodeBase* self);
  /*
  * Create bound witness, handle outcome, and store if needed
  */
  XYResult* (*doBoundWitness)(ByteArray* startingData, NetworkPipe* pipe);
  /*
  * Update the state of the origin chain.
  */
  XYResult* (*updateOriginState)(NodeBase* self);
  /*
  * Make a Payload* which can be used in a bound witness.
  */
  XYResult* (*makePayload)(NodeBase* self, uint bitFlag);

};

#define NODEBASE_H
#endif