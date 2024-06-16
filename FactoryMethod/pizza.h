#ifndef _PIZZA_
#define _PIZZA_



class Pizza{
    private:

    public:
        Pizza();
        virtual ~Pizza();
        virtual void prepare() = 0;
        virtual void bake() = 0;
        virtual void serve() = 0;


};
#endif
