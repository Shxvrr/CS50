#include <stdio.h>
#include <cs50.h>

int main() {
	long ccnumber = get_long_long("Number: ");

	long x = 10, y = 1;
	int i = 0, cc1 = 0, cc2 = 0, sum1 = 0, sum2 = 0;

	while (i < 8) {
		cc1 = (ccnumber / y) % 10;
		y = y * 100;
		cc2 = (ccnumber / x) % 10;
		x = x * 100;

		sum1 += cc1;

		if ((cc2 * 2) % 10 < (cc2 * 2)) {//if 2-digit number
			sum2 += ((cc2 * 2) / 10) % 10;//1st digit
			sum2 += (cc2 * 2) % 10;//2nd digit
		} else {
			sum2 += cc2 * 2;
		}

		i++;
	}

	long cc_count = ccnumber;
	string card_name;

	while (cc_count > 100) {
		cc_count = cc_count / 10;
	}

	if (cc_count == 37) {
		card_name = "AMEX";
	} else if (cc_count == 22 || cc_count == 55 || cc_count == 51) {
		card_name = "MASTERCARD";
	} else if (cc_count == 40 || cc_count == 41 || cc_count == 42) {
		card_name = "VISA";
	} else {
		card_name = "INVALID";
	}

	printf("%s\n", ((sum1+sum2) % 10 == 0) ? card_name : "INVALID");

	return 0;
}wget https://cdn.cs50.net/2022/fall/psets/6/sentimental-mario-less.zip