#include<stdio.h>

struct pair {
	int key;
	int value;
};

void display(struct pair arr[], int size) {

	printf("Key\tValue\n");

	for(int i=0; i<size; i++ ) {
		printf("%d\t%d\n", arr[i].key, arr[i].value);
	}
}

int main(int argc, char const *argv[]) {
	
	int size, i, temp;

	printf("Enter the size of the table: ");
	scanf("%d", &size);

	// creating a hash table (structure object)
	struct pair hash_table[size];

	printf("Enter the elements\n");

	for(i=0; i<size; i++) {
		scanf("%d", &temp);
		hash_table[temp % size].key = temp % size;
		hash_table[temp % size].value = temp;
	}
	printf("\n");
	display(hash_table, size);
	return 0;
}