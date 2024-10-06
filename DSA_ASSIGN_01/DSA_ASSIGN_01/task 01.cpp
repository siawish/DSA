//#include<iostream>
//using namespace std;
//template <typename T>
//class stack {
//private:
//	int top;
//	int size;
//	T* arr;
//
//public:
//	stack(int size) {
//		top = -1;
//		this->size = size ;
//		arr = new T[size];
//	}
//
//	~stack() {
//		delete[] arr;
//	}
//
//	T s_top() {
//		if(!isEmpty())
//		{
//			return arr[top];
//		}
//	}
//
//	void push(T element) {
//		if (isFull()) {
//			cout << "\n Stack Overflow!";
//			return;
//		}
//		if (isEmpty()|| arr[top]>= element) {
//			top++;
//			arr[top] = element;	
//			return;
//		}
//		else {
//			T temp = arr[top]; pop();
//
//			push(element);//recursive call
//
//			push(temp);// push(popped temp)
//		}
//	}
//
//	void pop() {
//		if (!isEmpty())  {
//			top--;
//		}
//		else {
//			cout << "\n Stack Underflow!";
//		}
//	}
//
//	bool isEmpty() {
//		return top == -1;
//	}
//
//	bool isFull() {
//		return top == size - 1;
//	}
//
//	int getMin() {
//		if (!isEmpty()) {
//			return arr[top];
//		}
//	 }
//	int siz() {
//		return this->top+1;
//	}
//};
//
//int main() {
//	string option;
//	do {
//		cout << "\n Enter size of a stack: ";
//		int size;
//		cin >> size;
//
//		stack<int> s(size);
//
//		int element;
//		cout << "\nEnter elements into the stack (-1 to stop): ";
//		while (true) {
//			cin >> element;
//			if (element == -1) break; 
//
//			s.push(element);
//		}
//		cout << "\n Size of stack: " << s.siz();
//		cout << "\n Minimum element in stack: " << s.getMin();
//
//		
//		cout << "\n Stack elements (top to bottom):";
//		while (!s.isEmpty()) {
//			cout << " " << s.s_top(); s.pop();                 
//		}
//
//		cout << "\n Do you want to create another stack? (yes/no): ";
//		cin >> option;
//	} while (option == "y" || option == "Y" || option == "yes" || option == "Yes");
//	
//	
//	return 0;
//}