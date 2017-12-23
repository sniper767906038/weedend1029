#include <stdio.h>
#include <string.h>

struct color_st {
	unsigned char red;
	unsigned char blue;
	unsigned char green;
};

struct pen_st {
	float price;
	struct color_st color;
	char logo[128];
} pen1, *pen2;

int main(void)
{
	pen2 = &pen1;

	pen1.price = 1.2;
	pen1.color.red = 100;
	pen1.color.blue = 90;
	pen1.color.green = 102;
	strcpy(pen1.logo, "zhencai");

	printf("%.4f, %d, %d, %d, %s\n", pen1.price, pen1.color.red,\
			pen1.color.blue, pen1.color.green, pen1.logo);
	printf("%.4f, %d, %d, %d, %s\n", pen2->price, pen2->color.red,\
			pen2->color.blue, pen2->color.green, pen2->logo);

	return 0;
}

