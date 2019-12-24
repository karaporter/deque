#ifndef __P04_H__
#define __P04_H__


// Represents a node in a doubly-linked list of integers.
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node() : data(0), next(nullptr), prev(nullptr) { }
    explicit Node(int elt) : data(elt), next(nullptr), prev(nullptr) { }
};


// Default exception for an empty deque.
class DequeEmptyException { };


// Represents a double-ended queue of integer values.
class Deque {
 public:
    // Constructs an empty deque.
    Deque();

    // Deallocates all memory for the deque.
    ~Deque();

    // Constructs the current object as a copy of orig.
    Deque(const Deque& orig);

    // Re-inializes the current object as a copy of rhs.
    Deque& operator=(const Deque& rhs);

    // Adds the specified elt to the front of the deque.
    void push_front(int elt);

    // Adds the specified elt to the back of the deque.
    void push_back(int elt);

    // Removes and returns the first element of the deque.
    // Throws a DequeEmptyException if the deque is empty.
    int pop_front();

    // Removes and returns the last element of the deque.
    // Throws a DequeEmptyException if the deque is empty.
    int pop_back();

    // Returns true if the deque contains no elements.
    bool is_empty() const;

    // Returns the number of elements in the deque.
    int size() const;

    // Removes all elements from the deque.
    void clear();

 private:
    Node* head;
    Node* tail;
    int length;

    // Copies the contents of source into destination,
    // such that destination is an exact copy of source.
    // As a precondition, this method assumes that
    // destination contains no elements.
    void copy(const Deque& source, Deque& destination);
};


#endif
