#include<iostream>
#include<cmath>
using namespace std;


class CComplex {
public:
    CComplex(double real = 0, double image = 0) :real(real), image(image) {}
    ~CComplex() {}//解析函数
    CComplex(CComplex& num) :real(num.real), image(num.image) {}
    void print() {
        cout << "real:" << real << endl;
        cout << "image:" << image << endl;
        cout << "复数形式为 " << real << "+" << image << "i" << endl;
    }

    bool operator == (CComplex& num) {
        return (real == num.real) && (image == num.image);
    }

    bool operator != (CComplex& num) {
        return (real != num.real) && (image != num.image);
    }

    friend CComplex operator+(CComplex& NUM, CComplex& num);

    friend CComplex operator-(CComplex& NUM, CComplex& num);


    CComplex& operator-=(const CComplex& NUM)
    {
        real -= NUM.real;
        image -= NUM.image;
        return *this;
    }

    CComplex& operator+=(const CComplex& NUM)
    {
        real += NUM.real;
        image += NUM.image;
        return *this;
    }


    CComplex operator++() {//前++运算符重载
        real++;
        image++;
        return *this;
    }


    CComplex operator++(int) {//后++ 
        CComplex VAL = *this;
        real++;
        image++;
        return VAL;
    }

    CComplex operator--() {//前置--
        real--;
        image--;
        return *this;
    }

    CComplex operator--(int) {//后置--
        CComplex temp = *this;
        real--;
        image--;
        return temp;
    }

    CComplex operator = (const CComplex& NUM) {
        CComplex VAL;
        real = NUM.real;
        image = NUM.image;
        return *this;
    }
private:
    double real;
    double image;
};

CComplex operator+(CComplex& NUM, CComplex& num) {
    CComplex VAL(0.0, 0.0);
    VAL.real = num.real + NUM.real;
    VAL.image = num.image + NUM.image;
    return VAL;
}

CComplex operator-(CComplex& NUM, CComplex& num) {
    CComplex VAL(0.0, 0.0);
    VAL.real = num.real - NUM.real;
    VAL.image = num.image - NUM.image;
    return VAL;
}

int main()
{
    double numR, numI;
    cout << "请输入实部:" << endl;
    cin >> numR;
    cout << "请输入虚部:" << endl;
    cin >> numI;
    CComplex ans1(numR, numI);
    CComplex ans2(7.6, 3.14);
    CComplex ans3(1.0, 1.0);
    ans3 = ans2+ans1;
    ans3.print();
    return 0;
}



}