
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
       typedef struct dlCahedNode{
           int index;
           dlNode *nodeAddress;
       } dlCahedNode; 

       int size; //Acual size of this list
       dlNode *First; //Pointer to first node (head)
       dlNode *Last; //Pointer to last node (tail) 



       public:
            dlList(){
               size = 0; 
               First = nullptr;
               Last = nullptr;
            }
            //Adds value (input) to front of the List
            int push_front(char input){
                dlNode *newNode =(dlNode*) malloc(sizeof(dlNode));
                newNode->value = input; 
                newNode->prev = nullptr;
                newNode->next = First;
                if(First != nullptr){
                    First->prev = newNode;
                }
                First = newNode;
                
                return 0;
            }
   }; 

}
