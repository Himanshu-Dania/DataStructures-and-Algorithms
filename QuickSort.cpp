#include <iostream>
using namespace std;

// Have you considered using autocompile?
// oh wait you have a script thats cool yes

// can you explain what the script does?
// I never saw anyone use a powershell script so im very curious
//idr it but ill send video link 
// so you didn't make it? yea
int PivotIndex(int arr[], int low, int high)
{
    
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (pivot >= arr[i])
        {
            i++;
        }
        while (pivot < arr[j])
        {
            j--;
        }
        if(i<j){
        swap(arr[i], arr[j]);
        }

    } while (i < j);
    swap(arr[low], arr[j]);
    return j;
}

/**
 * @brief QS is the recursive part, pivotindex gives index of pivot after one sorting call
 *
 * @param arr the array that will be sorted
 * @param low ??? iterator l to r
 * @param high iterator r to l
 */
void QuickSort(int arr[], int low, int high)
{
    int pivindex;
    
    if(low < high)
    { 
        // to stop recursion when low=high=0
        pivindex = PivotIndex(arr, low, high);
        QuickSort(arr, low, pivindex - 1);
        QuickSort(arr, pivindex + 1, high);
    }
}

// In order to make a recursive algorithm, you have to pass in dynamic arrays
// and since

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << ", ";
    }

    // Generally a good idea to flush after many couts;Whats flush
    flush(cout);
}

void verifyArray(int arr[]) {
    // I'm going to morb
    // the value below gives us the minimum value of an int
    int last = 1 << 31;
    // int last = (unsigned int) -1;
    //is that bit manipulation omg
    // yeah I was just a little rusty
    // This should give the lowest value of an int
    // 0b10000000000000000000000000000000 (31 following 0s) whats 0b? negative sign?
    // 0b stands for binary ohhhh
    // 0b11 is 3
    // 0x - hex
    // 0o - oct (base 8)
    // 0b - binary
    //how do u indicate negative in binary
    // for negative numbers, it starts with 1
    // so when you reach 0b01111111111111111111111111111111, it will overflow to 0b10000000000000000000000000000000
    // which is an integer overflow
    // this makes more sense to the computer than to humans
    //my brain is blown xD
    // making negative numbers start from 0b1... makes adding negative numbers with positive numbers a lot more easier
    // when you add -1 to 3, its actually overflowing from -1
    // because -1 is 0b11111111111111111111111111111111
    //I havent covered this part yet honestly
    // oh, you will learn it later yea
    //tmr im starting trees (my 2c, trees are easier to learn in python (and oop langs with gc in general))
    //gc? (garbage collector) whats thattttt
    // basically when you malloc(), you have to free() right? ye
    // or in cpp, new, and delete which i never do myself
    // well, thats because the program does not know which data is not used anymore
    // so the program will not free it unless explicitly asked to(doesnt it delete automatically after main is done no)
    // well, actually, the program does not delete, but the operating system does free the memory
    // and what you just said is kinda bad practice
    // what if your program is used as a library? then you can't rely on main() ending(didnt think kof that)
    // anyway, in python and other oop languages, the program will automatically free the memory when it is not used anymore
    // its done in a way called reference counting
    // so when you create a variable, the program will increase the reference count by 1
    //ive heard of it actually
    // if the lexical scope ends i.e end of backet, it decreases the reference count by 1
    // if the reference count is 0, it will free the memory
    // if you have another object that has its property as the variable, the reference count is also increased by 1
    // (there are separate algorithms that help calculate circular references but I won't talk about that right now. The algorithm
    // above is the basic idea of gc)
    // The ONLY language that has automatic memory lifetime management without a GC is Rust
    // rust supreme :dab: lmao
    // but at the same time rust has things like Arc (atomic reference counting) and Box, Cell, Rc, RefCell, UnsafeCell ... 
    // not really the easiest language
    //btw can you see my other files or only this one
    // all files in your current folder(holy shit xD)
    // yeah your code is holy shit whaaat
    // you can ask me to review a file if you want
    //idk which one
    //the linked list ones definatel have worst memory management
    // i have had my laughs so don't worry about being embarassed
    
    
    cout<<last<<endl;//just wanna see
    for (int i = 1; i < 1000; i++){
        
        if(last>arr[i]){
            cout<<"Unsorted Array"<<endl;
            exit(1);
        }
        last = arr[i];
    }
    cout<<"Sorted Array"<<endl;
    //what r u tryin to do
}
    

//I think recursion isnt stopping
int main()
{
    int arr[1000];
    for(int i =0;i<1000;i++){
        arr[i]=rand();
    }
    // printArray(arr,1000);
    QuickSort(arr, 0, 999);
    // printArray(arr, 1000);
    verifyArray(arr);
    return 0;
}