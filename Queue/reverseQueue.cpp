//A program to reverse a queue using a stack.
# include <iostream>
# include <queue>
# include <stack>

using namespace std;

void printQueue(queue <int> Queue)
{
    while(!Queue.empty())
    {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}

void reverseQueue(queue <int> &Queue)
{
    stack <int> Stack;

    while(!Queue.empty())
    {
        Stack.push(Queue.front());
        Queue.pop();
    }

    while(!Stack.empty())
    {
        Queue.push(Stack.top());
        Stack.pop();
    }

}

int main(void)
{
    queue <int> Queue;
    Queue.push(1);
    Queue.push(2);
    Queue.push(3);
    Queue.push(4);
    Queue.push(5);
    cout << "Queue before reversal : ";
    printQueue(Queue);
    reverseQueue(Queue);
    cout << "\nQueue after reversal : ";
    printQueue(Queue);
    return 0;
}
