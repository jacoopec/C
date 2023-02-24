int main(){
       char* c = (char *)&s;
        void* p = (void *)&s;
        int* pi = (int *)&s;
        double* pd = (double *)&s;

        std::cout << "Void " << p << "   size of void " << sizeof(p) <<  std::endl;
        std::cout << "Char " << c << "   size of char " << sizeof(c) <<  std::endl;
        std::cout << "Int " << pi << "   size of int " << sizeof(pi) <<  std::endl;
        std::cout << "Double " << pd << "   size of double " << sizeof(pd) <<  std::endl;
}