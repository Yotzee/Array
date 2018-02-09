C++ Dynamic Array

```
	Array<int> numbers; // creates array of size 200 and will increase size every 200
	Array<int> numbers = Array<int>(500); // creates array of size 500 and will increase size every 200
	numbers += 1; // add number
	numbers.remove(0); // remove first object

	/// add 10000 numbers (int) 
	/// will dynamic size array every 200 objects
	for(int i = 0; i < 10000; i++){
		numbers += i;
	}
```
