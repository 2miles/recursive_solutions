#include "table.h"
//////////////////////////////////////////////////////////////////////////////
// Return true if roots data appears more than once, else return false.
//////////////////////////////////////////////////////////////////////////////
bool table::appear_twice()
{
    if (!root)
        return false;
    if (!root->right)
        return false;
    return appear_twice(root->right, this->root->data);
}

// Private recursive
bool table::appear_twice(node *root, int rootData)
{
    // do an in-order traversal
    // if roots data is the same as this->roots data then return true

    bool result;
    if (!root)
        return false;
    result = appear_twice(root->left, rootData);
    if (root->data == rootData)
        return true;
    return result;
}

//////////////////////////////////////////////////////////////////////////////
// Returns the level of the first occurence of node with data = 15.
// Else return 0.
//////////////////////////////////////////////////////////////////////////////
int table::level_of_first()
{
    bool found = false;
    if (!root)
        return 0;
    return level_of_first(root, found);
}

// Private recursive
int table::level_of_first(node *root, bool &found)
{
    int level = 0;
    if (!root)
        return 0;
    if (root->data == 15)
    {
        found = true;
        return 1;
    }
    if (found)
        ++level;
    level += level_of_first(root->left, found);
    level += level_of_first(root->right, found);
    return level;
}

//////////////////////////////////////////////////////////////////////////////
// Returns the data the occurs most frequently.
// If none occur most frequent, return the smalled data.
//////////////////////////////////////////////////////////////////////////////
int table::most_frequent()
{
    int count = 0;
    int mostFreq = 0;
    int largest = 0;
    int prev = 0;

    if (!root)
        return 0;
    most_frequent(root, root->data, mostFreq, count, largest);
    cout << endl;
    return mostFreq;
}

// Private recursive
void table::most_frequent(node *root, int &prev, int &mostFreq, int &count, int &largest)
{
    if (!root)
        return;

    most_frequent(root->left, prev, mostFreq, count, largest);

    if (root->data == prev)
        ++count;
    else
        count = 1;
    if (count > largest)
    {
        largest = count;
        mostFreq = root->data;
    }
    prev = root->data;
    most_frequent(root->right, prev, mostFreq, count, largest);
}

//////////////////////////////////////////////////////////////////////////////
// Returns the average of all the data in the BST.
//////////////////////////////////////////////////////////////////////////////
int table::average()
{
    int sum = 0;
    if (!root)
        return 0;
    int number = average(root, sum);
    cout << "Sum: " << sum << endl;
    cout << "Num: " << number << endl;
    return sum / number;
}

// Private recursive
int table::average(node *root, int &sum)
{
    int count = 0;
    if (!root)
        return 0;

    count = average(root->left, sum);
    sum += root->data;
    count += average(root->right, sum) + 1;
    return count;
}

//////////////////////////////////////////////////////////////////////////////
// Returns the level of the last occurence of node with data = 15,
// when traversing in order. Else returns 0.
//////////////////////////////////////////////////////////////////////////////
int table::last_15()
{
    bool found = false;
    if (!root)
        return 0;
    last_15(root, found);
    return last_15(root, found);
}

// Private recursive
int table::last_15(node *root, bool &found)
{
    int level = 0;
    if (!root)
    {
        return 0;
    }
    level = last_15(root->right, found);
    level = last_15(root->left, found);
    if (root->data == 15 && !found)
    {
        found = true;
        return 1;
    }
    if (!found)
        return 0;
    else
        return level + 1;
}

//////////////////////////////////////////////////////////////////////////////
// Returns roots in-order-successor.
//////////////////////////////////////////////////////////////////////////////
int table::retrieve_IOS()
{
    if (!root)
        return 0;
    if (!root->right)
        return 0;
    return retrieve_IOS(root->right);
}

// Private recursive
int table::retrieve_IOS(node *root)
{
    if (!root->left)
        return root->data;
    return retrieve_IOS(root->left);
}

//////////////////////////////////////////////////////////////////////////////
// Returns the average of the data in root's in-order-successor's
// right sub-tree.
//////////////////////////////////////////////////////////////////////////////
int table::average_IOS()
{
    int sum = 0;
    if (!root)
        return 0;
    if (!root->right)
        return 0;
    node *ios = get_IOS(root->right);
    int result = number_of_nodes(ios->right, sum);
    int theAverage;
    cout << "result = " << result << endl;
    if (result == 0)
        theAverage = 0;
    else
        theAverage = sum / result;
    return theAverage;
}

// Private recursive
int table::number_of_nodes(node *root, int &sum)
{
    int total = 0;
    if (!root)
        return 0;
    total = number_of_nodes(root->left, sum);
    sum += root->data;
    ++total;
    total += number_of_nodes(root->right, sum);
    return total;
}
// Private helper
node *table::get_IOS(node *root)
// returns the ios when called with root->right
{
    if (!root->left)
        return root;
    return get_IOS(root->left);
}

//////////////////////////////////////////////////////////////////////////////
// Returns the level of the first occurence of given number when
// doing an in order traversal.
//////////////////////////////////////////////////////////////////////////////
int table::level_of_first_data(int number)
{
    bool found = false;
    if (!root)
        return 0;
    return level_of_first_data(root, number, found);
}

// Private recursive
int table::level_of_first_data(node *root, int number, bool &found)
{
    int count = 0;
    if (!root)
        return 0;
    if (root->data == number)
    {
        found = true;
        return 1;
    }
    if (root->data < number)
        count = level_of_first_data(root->right, number, found);
    else
        count += level_of_first_data(root->left, number, found);
    if (found)
        ++count;
    return count;
}

//////////////////////////////////////////////////////////////////////////////
// Returns the level of the last occurence of given number when doing
// an in order traversal.
//////////////////////////////////////////////////////////////////////////////
int table::level_of_last_data(int number)
{
    bool found = false;
    if (!root)
        return 0;
    return level_of_last_data(root, number, found);
}

// Private recursive
int table::level_of_last_data(node *root, int number, bool &found)
{
    int count = 0;
    if (!root)
        return 0;
    if (root->data <= number)
        count = level_of_last_data(root->right, number, found);
    else
        count += level_of_last_data(root->left, number, found);
    if (root->data == number && !found)
    {
        found = true;
        return 1;
    }
    if (found)
        ++count;
    return count;
}

//////////////////////////////////////////////////////////////////////////////
// Display all the data on a given level and return the average of that data.
//////////////////////////////////////////////////////////////////////////////
int table::display_level(int number)
{
    int level = 0;
    int sum = 0;
    int total = 0;
    if (!root)
        return 0;
    total = display_level(root, level, number, sum);
    return sum / total;
}

// Private recursive
int table::display_level(node *root, int &level, int number, int &sum)
{
    int total = 0;
    if (!root)
        return 0;
    ++level;
    if (level == number)
    {
        cout << root->data << ' ';
        sum += root->data;
        --level;
        return 1;
    }
    total = display_level(root->left, level, number, sum);
    total += display_level(root->right, level, number, sum);
    --level;
    return total;
}

//////////////////////////////////////////////////////////////////////////////
// Display the data along the longest path from root to leaf and return
// the average of that data.
//////////////////////////////////////////////////////////////////////////////
int table::longest_path_avg()
{
    int sum = 0;
    bool found = false;
    int level = 0;
    if (!root)
        return 0;
    int height = find_height(root);
    int count = longest_path_avg(root, level, found, height, sum);
    return sum / count;
}

// Private Recursive
int table::longest_path_avg(node *root, int &level, bool &found, int height, int &sum)
{
    int total = 0;
    if (!root)
        return 0;
    ++level;
    if (level == height)
    {
        found = true;
        sum += root->data;
        cout << root->data << ' ';
        --level;
        return 1;
    }
    total = longest_path_avg(root->left, level, found, height, sum);
    if (!found)
        total += longest_path_avg(root->right, level, found, height, sum);
    --level;
    if (found)
    {
        sum += root->data;
        cout << root->data << ' ';
        ++total;
    }
    return total;
}

// Private helper
int table::find_height(node *root)
{
    if (!root)
        return 0;
    return max(find_height(root->left), find_height(root->right)) + 1;
}
