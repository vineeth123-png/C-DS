class node{
        public:
        node* left;
        int data;
        node* right;
        //constructors
        node(int val = -1){
                data = val;
                left = NULL;
                right = NULL;
        }
        node(int valIn, node* pre, node* ne){
                left = pre;
                data = valIn;
                right = ne;
        }
        //deconstructor
        ~node(){}
};
