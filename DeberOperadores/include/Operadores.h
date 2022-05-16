#ifndef OPERADORES_H
#define OPERADORES_H


class Operadores
{
    public:
        Operadores();
        Operadores(int, int);
        bool operator&&(Operadores otro);
        int operator&=(int);
    protected:

    private:
        int num1;
        int num2;
        int num3;
        int num4;
};

#endif // OPERADORES_H
