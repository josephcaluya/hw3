#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;
  void heapify(int index);
  void trickleUp(int location);
private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heapList;
  unsigned int size_;
  int ary_;
  PComparator comparator_;
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) :
  ary_(m), comparator_(c) 
{
  size_ = 0;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() 
{

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  heapList.push_back(item);
  ++size_;
  trickleUp(heapList.size()-1);
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return size_ == 0;
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return size_;
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heapList[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  heapList[0] = heapList.back();
  heapList.pop_back();
  heapify(0);
  size_--;
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int index)
{
  if ((ary_*index + 1) > size()-1) {
		return;
	}
	int leftChild = ary_*index + 1;
	int bestChild = leftChild;
  int i = 2;
	while ((ary_*index + i) < size() && i <= ary_) {
    int tempChild = ary_*index + i;
    if (comparator_(heapList[tempChild], heapList[bestChild])) {
        bestChild = tempChild;
    }
    ++i;
	}
	if (comparator_(heapList[bestChild], heapList[index])) {
			std::swap(heapList[index], heapList[bestChild]);
			heapify(bestChild);
	}
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int location)
{
  int parent = (location-1)/ary_;
  while(parent >= 0 && comparator_(heapList[location], heapList[parent])) {
    std::swap(heapList[parent], heapList[location]);
    location = parent;
    parent = (location-1)/ary_;
  }
}

#endif

