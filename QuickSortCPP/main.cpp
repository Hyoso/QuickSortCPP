#include <iostream>

const int MAX_CHAR = 123;
char charArray[MAX_CHAR] = "daczxcvbpoiuytresdfghjkydcefiashjfahsifulhwlkjhgfdsxcvbnmainasdacfwabnmswqqdssdfgsdfgbauscaaiuqgmhjmoiuytrewqasdfghjklokl";

void QuickSort(char toSort[MAX_CHAR], int start, int end)
{
	// find a pivot
	// increment leftIndex until next character > pivot is found
	// decrement rightIndex until next character < pivot is found
	// if leftIndex is still < right index then swap and move onto next indices

	// partition and recurse
	char pivot = toSort[(start + end) / 2];

	int leftIndex = start, rightIndex = end;
	while (true)
	{
		while (charArray[leftIndex] < pivot)
		{
			leftIndex++;
		}
		while (charArray[rightIndex] > pivot)
		{
			rightIndex--;
		}

		if (leftIndex < rightIndex)
		{
			char copy = charArray[leftIndex];
			charArray[leftIndex] = charArray[rightIndex];
			charArray[rightIndex] = copy;

			leftIndex++;
			rightIndex--;
		}
		else
		{
			break;
		}
	}

	if (start < leftIndex)
	{
		QuickSort(toSort, start, leftIndex - 1);
	}
	if (rightIndex < end)
	{
		QuickSort(toSort, rightIndex + 1, end);
	}
}

int main()
{
	std::cout << "unsorted: " << charArray << std::endl;
	QuickSort(charArray, 0, MAX_CHAR - 2); // -2 to omit the escape character
	std::cout << "sorted: " << charArray << std::endl;

	return 0;
}