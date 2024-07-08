#include <iostream>
#include <vector>

uint64_t beautiful_number(int N, int base)
{
	// quantity of the sum which given a number 0 .. N / 2 * base
	std::vector<uint64_t> sum_digit(N / 2 * base, 0);

	// vector with total sum of digits for each N numbers
	// size of vec = max sum of digits
	std::vector<uint64_t> total(N / 2 * base, 0);

	// base case (for N = 1)
	for (int i = 0; i < base; ++i)
		total[i] = 1;

	// iterate over all values starting with N=2 to N
	// N / 2 cuz length(number) = N then sum_of_left = sum_of_right = N / 2
	// excepting central digit if it's over there
	for (int i = 2; i <= (N / 2); ++i)
	{
		// for each iteration max sum of digits
		int max_sum_digit = i * (base - 1);
		int max_total = max_sum_digit - (base - 1);

		// save the vector "total" from the previous iteration to "sum_digit"
		for (uint64_t j = 0; j <= max_total; ++j)
			sum_digit[j] = total[j];
		
		// clean total for cur iteration (the copy is in digit)
		for (uint64_t j = 0; j < max_sum_digit; ++j)
			total[j] = 0;

		// iteration of possible variant of digit
		for (uint64_t j = 0; j < base; ++j)
			// iteraton of all answer the last iteration
			for (uint64_t ans = 0; ans <= max_total; ++ans)
				total[ans + j] += sum_digit[ans];

	}

	// SQR is needed for accounting left and ritgh sides
	uint64_t result{};
	for (auto& i : total)
		result += i * i;

	// take into account the central digit
	int central_digit = (N % 2) ? base : 1;

	return result * central_digit;
}

int main()
{
	// according to the condition N = 13 and base_system = 13
	std::cout << beautiful_number(13, 13);
	return 0;
}