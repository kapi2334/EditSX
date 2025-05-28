
#include <cstdlib>
namespace sxEditCore::dataStructures{


    class dlList{
        private:
            //Single node declaration
            typedef struct dlNode{
                char value;
                struct dlNode* next;
                struct dlNode* prev;
            } dlNode; 

            //Cahed node declaration
            typedef struct dlCachedNode{
                int index = -1;
                dlNode *nodeAddress= nullptr;
            } dlCachedNode; 

            //TO DO: CALCULATING THE THERSHOLD VALUE DEPENDING ON THE SIZE VARIABLE
            int cacheTreshold = 20;
            dlCachedNode cachedNode; 

            int size; //Acual size of this list
            dlNode *First; //Pointer to first node (head)
            dlNode *Last; //Pointer to last node (tail) 


            /*It is used to obtain a node at a specific position - using the node stored in memory.
             *Returns nullptr when cashing attempt failed - fe. if CahedNode is empty, 
             or if targetted node and cahed one are too away.
             * */
            dlNode* tryToCahe(int nodeIndex){
                if(cachedNode.nodeAddress == nullptr ) return nullptr; //If cahed node doesnt exist
                if(nodeIndex >= size || nodeIndex < 0) return nullptr; //If index is outside the array
                    if(std::abs(nodeIndex - cachedNode.index) < cacheTreshold){ //Success - finding node using one in cashe can be done.
                        //Cashe types
                        if(nodeIndex - cachedNode.index > 0 ){
                            //Iterating to node from cached one using next property.
                            
                            while(cachedNode.index <= nodeIndex){
                               cachedNode.index++;
                               cachedNode.nodeAddress = cachedNode.nodeAddress->next;
                            }
                            return cachedNode.nodeAddress;
                        }
                        else if(nodeIndex - cachedNode.index == 0 ){
                            //Requested node its that one in the cache
                            return cachedNode.nodeAddress;
                        }
                        else if(nodeIndex - cachedNode.index < 0 ){
                            //Iterating to node from cahed one using prev property.

                            while(cachedNode.index >= nodeIndex){
                                
                               cachedNode.index--;
                               cachedNode.nodeAddress = cachedNode.nodeAddress->prev;
                            }
                            return cachedNode.nodeAddress;
                        }

                    }
                return nullptr;        
                
                
            }


        public:
            dlList(){
                size = 0; 
                First = nullptr;
                Last = nullptr;
            }
            //Adds value (input) to the front of the List
            int pushFront(char input){
                dlNode *newNode =(dlNode*) malloc(sizeof(dlNode));
                newNode->value = input; 
                newNode->prev = nullptr;
                newNode->next = First;
                if(First != nullptr){
                    First->prev = newNode;
                }
                First = newNode;
                size++;
                return 0;
            }
            //Adds value (input) to the back of the list
            int pushBack(char input){
                dlNode* newNode = (dlNode*)malloc(sizeof(dlNode));
                newNode->value = input;
                newNode->next = nullptr;

                if(First == nullptr){
                    newNode->prev = nullptr;
                    First = newNode;
                    Last = newNode;
                    return 0;
                }

                newNode -> prev = Last;
                Last -> next = newNode;
                Last = newNode;

            }

    }; 

}
