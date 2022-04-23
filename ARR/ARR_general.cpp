#include "arr.h"
//////////////////////////////////////////////////////////////////////////////
// Return the number of nodes
//////////////////////////////////////////////////////////////////////////////
int table::count_nodes()
{
    if (!head)
        return 0; // there is no array
    return count_nodes(0);
}

// Private recursive
int table::count_nodes(int i)
{
    if (i == size)
        return 0;                 // have reached the end of the array
    node *current_head = head[i]; // pointing to first node of array element
    int count = count_nodes(current_head);
    count += count_nodes(++i);
    return count;
}

// Private recursive
int table::count_nodes(node *head)
{
    if (!head)
        return 0;
    return count_nodes(head->next) + 1;
}
//////////////////////////////////////////////////////////////////////////////
// Display all the nodes. Return the number of nodes displayed
//////////////////////////////////////////////////////////////////////////////
int table::my_display()
{
    if (!head)
        return 0; // array is NULL
    return my_display(head);
}

int table::my_display(node **head)
{
    int count = 0;
    if (head == this->head + size) // we have gone past the array
        return 0;
    count = my_display(*head); // call list display, grab count
    cout << endl;
    return my_display(++head) + count; // call array display on next list, adding count
}

int table::my_display(node *head)
{
    if (!head)
        return 0;
    cout << head->data << ' ';
    return my_display(head->next) + 1;
}

//////////////////////////////////////////////////////////////////////////////
// Display all the nodes. Return the number of nodes displayed
//////////////////////////////////////////////////////////////////////////////
int table::display_all()
{
    if (!head)
        return 0;
    return display_all(0);
}

int table::display_all(int i)
{
    int count = 0;
    if (i == size)
        return 0;
    node *current_head = head[i];
    count = display_all(current_head);
    return count += display_all(++i);
}

int table::display_all(node *head)
{
    if (!head)
        return 0;
    if (!head->next)
    {
        cout << head->data << ' ';
        cout << endl;
    }
    else
        cout << head->data << ' ';
    return display_all(head->next) + 1;
}

//////////////////////////////////////////////////////////////////////////////
// Display all the nodes. Return the number of nodes displayed
//////////////////////////////////////////////////////////////////////////////
int table::display_v2()
{
    if (!head)
        return 0;
    return display_v2(head);
}

int table::display_v2(node **head)
{
    int count = 0;
    if (head == this->head + size)
        return 0;
    count = display_v2(*head);
    return count += display_v2(++head);
}

int table::display_v2(node *head)
{
    if (!head)
        return 0;
    cout << head->data << ' ';
    if (!head->next)
        cout << endl;
    return display_v2(head->next) + 1;
}

//////////////////////////////////////////////////////////////////////////////
// Displays every other data in the array of linked lists. Returns the number
// of nodes displayed
//////////////////////////////////////////////////////////////////////////////
int table::display_every_other()
{
    if (!head)
        return 0;
    return display_every_other(head);
}

int table::display_every_other(node **head)
{
    int total = 0;
    if (head == this->head + size)
        return 0;
    total = display_every_other(*head);
    return total += display_every_other(++head);
}

int table::display_every_other(node *head)
{
    int count = 0;
    if (!head)
    {
        cout << endl;
        return 0;
    }
    cout << head->data << ' ';
    head = head->next;
    if (head)
    {
        ++count;
        if (head->next)
            return display_every_other(head->next) + count;
    }
    cout << endl;
    return count;
}

//////////////////////////////////////////////////////////////////////////////
// Return the sum of the even data
//////////////////////////////////////////////////////////////////////////////
int table::sumEvens()
{
    if (!head)
        return 0;
    return sumEvens(head);
}

int table::sumEvens(node **head)
{
    int sum = 0;
    if (this->head + size == head)
        return 0;
    sum = sumEvens(*head);
    cout << endl; // new line between lists
    return sumEvens(++head) + sum;
}

int table::sumEvens(node *head)
{
    if (!head)
        return 0;
    if (head->data % 2 == 0)
    {
        cout << head->data << ' ';
        return sumEvens(head->next) + head->data;
    }
    return sumEvens(head->next);
}

//////////////////////////////////////////////////////////////////////////////
// Copy the array of linked lists. Return the number of nodes copied.
//////////////////////////////////////////////////////////////////////////////
int table::copy(table &to_copy)
{
    if (!to_copy.head)
    {
        this->head = NULL;
        return 0;
    }
    size = to_copy.size;
    head = new node *[size];
    return copy(head, to_copy.head);
}

int table::copy(node **destArray, node **sourceArray)
{
    int count = 0;
    if (this->head + size == destArray)
        return 0;
    count = copy(*destArray, *sourceArray);
    return copy(++destArray, ++sourceArray) + count;
}

int table::copy(node *&dest_head, node *source_head)
{
    if (!source_head)
        return 0;
    dest_head = new node;
    dest_head->next = NULL;
    dest_head->data = source_head->data;
    return copy(dest_head->next, source_head->next);
}

//////////////////////////////////////////////////////////////////////////////
// Returns true if the sum of the data longest in the shortest linked list in
// the array devides the sum of the data in the longest linked list in the array
//////////////////////////////////////////////////////////////////////////////
bool table::devide_special()
{
    int longest = 0;     // length of the longest LLL
    int shortest = 1000; // length of the shortest LLL
    int sumLongest = 0;  // sum of longest LLL
    int sumShortest = 0; // sum of shortest LLL
    int count = 0;       // length of the current LLL

    if (!head)
        return 0;
    devide_special(head, longest, shortest, count, sumLongest, sumShortest);
    int result = sumLongest % sumShortest;
    // result evaluates to 0 if sum of longest devides sum of shortest

    cout << "sumLongest: " << sumLongest << endl;
    cout << "sumShortest: " << sumShortest << endl;
    cout << "longestLength: " << longest << endl;
    cout << "shortestLength: " << shortest << endl;
    cout << "result: " << result << endl;
    return !result; // return true if result is 0;
}

// traverses through each LLL in the array
// finding the longest and shortest LLL and both their data sums
void table::devide_special(node **head, int &longest, int &shortest,
                           int &count, int &sumLongest, int &sumShortest)
{
    int sum = 0;
    if (head == this->head + size)
        return;
    count = count_nodes(*head, sum);
    if (count > longest)
    {
        longest = count;
        sumLongest = sum;
    }
    if (count < shortest)
    {
        shortest = count;
        sumShortest = sum;
    }
    devide_special(++head, longest, shortest, count, sumLongest, sumShortest);
}

// return the number of nodes in a LLL
// also update sum with the sum of the data in this LLL
int table::count_nodes(node *head, int &sum)
{
    if (!head)
        return 0;
    sum += head->data;
    return count_nodes(head->next, sum) + 1;
}

//////////////////////////////////////////////////////////////////////////////
// Append the first list in the array to all the other lists.
// Return 1 if any lists were appended, else return 0
//////////////////////////////////////////////////////////////////////////////
int table::append_to_all()
{
    if (!head)
        return 0; // the array pointer is empty
    if (size < 2)
        return 0;        // the list has only one list, so do nothing
    append_to_all(head); // start processing the first list
    return 1;
}

void table::append_to_all(node **head)
{
    if (head == this->head + size)
        return;
    append_to_all(*head);
    append_to_all(++head);
}

// append the first list to the end of the list.
void table::append_to_all(node *head)
{
    // traverse to end of the list
    // then call the append list function
    // using *(this->head) as source argument

    if (!head)
    {
        append_list(*(this->head), head);
        return;
    }
    append_to_all(head->next);
}

// copy a list
void table::append_list(node *source, node *&dest)
{
    if (!source)
    {
        dest = NULL;
        return;
    }
    dest = new node;
    dest->data = source->data;
    append_list(source->next, dest->next);
}
