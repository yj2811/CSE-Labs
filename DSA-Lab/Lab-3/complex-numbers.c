#include<stdio.h>

typedef struct{
	int real;
	int img;
} Complex;

Complex add(Complex c1, Complex c2){
	Complex ans;

	ans.real = c1.real + c2.real;
	ans.img = c1.img + c2.img;

	return ans;
}

Complex subtract(Complex c1, Complex c2){
	Complex ans;

	ans.real = c1.real - c2.real;
	ans.img = c1.img - c2.img;

	return ans;
}

Complex multiply(Complex c1, Complex c2){
	Complex ans;

	ans.real = (c1.real * c2.real) - (c1.img * c2.img);
	ans.img = (c1.real * c2.img) + (c1.img * c2.real);

	return ans;
}

int main(){
	Complex c1, c2, sum, difference, product;

	printf("Enter the real and imaginary part of the first complex number:\n");
	scanf("%d %d", &(c1.real), &(c1.img));

	printf("Enter the real and imaginary part of the second complex number:\n");
	scanf("%d %d", &(c2.real), &(c2.img));

	sum = add(c1, c2);
	difference = subtract(c1, c2);
	product = multiply(c1, c2);

	printf("Sum: %d +%di.\n", sum.real, sum.img);
	printf("Difference: %d +%di.\n", difference.real, difference.img);
	printf("Product: %d +%di.\n", product.real, product.img);

}
