#include<iostream>
#include<algorithm>
#include<list>

int main()
{

	return 0;
}

void commands() //function that prints all program commands
{ 
		cout<<"Program commands: "<<endl
		<<"help"<<endl
		<<"pwd"<<endl
		<<"realpath <filename>"<<endl
		<<"ls"<<endl
		<<"ls sort"<<endl
		<<"mkdir <foldername>"<<endl
		<<"touch <filename size>"<<endl
		<<"cd <foldername>"<<endl	
		<<"cd <filename>"<<endl
		<<"cd .."<<endl
		<<"cd -"<<endl
		<<"cd </my/path/name>"<<endl
		<<"find <foldername>"<<endl
		<<"find <filename>"<<endl
		<<"mv <filename foldername>"<<endl
		<<"rm <foldername>"<<endl
		<<"rm <filename>"<<endl
		<<"size <foldername>"<<endl;
		<<"size <filename>"<<endl;
		<<"emptybin"<<endl;
		<<"showbin"<<endl;
		<<"recover"<<endl;
		<<"exit"<<endl;

}

class Inode //creating the node that represents an inode
{
	public: 
		string name; //name of the file/folder
		int size; //size of the file/folder
		bool file; //true if inode is a file, false if a folder
		time_t date; //attribute of system file
		Inode* parent; //pointer that points to parent node
		MyVector<Inode*> children; //extendable array of children nodes;

}

template <typename T>
class MyVector
{
	private:
		T *data;						//pointer to int(array) to store elements
		int v_size;						//current size of vector (number of elements in vector)
		int v_capacity;					//capacity of vector
	public:
		MyVector();						//No argument constructor
		MyVector(int cap);				//One Argument Constructor
		MyVector(MyVector& other);		//Copy Constructor
		~MyVector();					//Destructor
		void push_back(T element);		//Add an element at the end of vector
		void insert(int index, T element); //Add an element at the index 
		void erase(int index);			//Removes an element from the index
		T& operator[](int index);		//return reference of the element at index
		T& at(int index); 				//return reference of the element at index
		const T& front();				//Returns reference of the first element in the vector
		const T& back();				//Returns reference of the Last element in the vector
		int size() const;				//Return current size of vector
		int capacity() const;			//Return capacity of vector
		bool empty() const; 			//Rturn true if the vector is empty, False otherwise
		void shrink_to_fit();			//Reduce vector capacity to fit its size
		void display();
};

template <typename T> MyVector<T>::MyVector() {
	v_size = 0;
	v_capacity = 0;
	data = new T[NULL];
};


template <typename T> MyVector<T>::MyVector(int cap) {
	v_size = 0;
	v_capacity = cap;
	data = new T[NULL];
};

template <typename T> MyVector<T>::MyVector(MyVector& other) {
	v_size = other.v_size; 
	v_capacity = other.v_capacity; 
	data = other.data;
}

template <typename T> MyVector<T>::~MyVector() {
	delete[] data;
};

template <typename T> int MyVector<T>::size() const {
	return v_size;
};

template <typename T> int MyVector<T>::capacity() const {
	return v_capacity;
};

template <typename T> T& MyVector<T>::operator[](int index) {
	return data[index];
};


template <typename T> bool MyVector<T>::empty() const {
	return v_size == 0;
};

template <typename T> const T& MyVector<T>::front() {
	if(empty())
	{
		cout<<"Vector is empty!"<<endl;
	}
	return data[0];
}

template <typename T> const T& MyVector<T>::back() {
	if(empty())
	{
		cout<<"Vector is empty!"<<endl;
	}
	return data[v_size-1];
}

template <typename T> T& MyVector<T>::at(int index) {
	if(v_size <= index || index < 0)
	{
		throw runtime_error("Index is out of bounds!");
	}
	return data[index];
};

template <typename T> void MyVector<T>::erase(int index) {
	if(v_size<=index || index<0)
	{
		throw runtime_error("Index is out of bounds!");
	}
	for(int i=index+1;i<size();i++)
	{
		data[i-1] = data[i];
	}
	v_size --;
};

template <typename T> void MyVector<T>::insert(int index, T element)
{
	if(index < 0 || (index > size()-1))
	{
		throw runtime_error("Index is out of bounds!");
		return;
	}

	if(v_size >= v_capacity)
	{
		int n_cap = 2 * max(1,v_capacity);
		T* newV = new T[n_cap];

		for(int i=0; i<v_size; i++)
		{
			newV[i] = data[i];
		}

		if(data != NULL)
		{
			delete[] data;
		}

		data = newV; 
		v_capacity = n_cap;

	} 

	for(int i=v_size -1; i>= index; i--)
	{
		data[i+1]=data[i];
	}
	data[index] = element; 
	v_size++;

};

template <typename T> void MyVector<T>::shrink_to_fit()
{
	v_capacity = v_size;
}


template <typename T> void MyVector<T>::push_back(T element) {

	if(v_size >= v_capacity)
	{
		int n_cap = 2 * max(1,v_capacity);
		T* newV = new T[n_cap];

		for(int i=0; i<v_size; i++)
		{
			newV[i] = data[i];
		}

		if(data != NULL)
		{
			delete[] data;
		}

		data = newV; 
		v_capacity = n_cap;

	} 

	data[size()] = element; 
	v_size++;
};

