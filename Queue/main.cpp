#include "queue.h"
#include <iostream>

int main() 
{
	g3::queue<int> myQueue;

	myQueue.push(10);
	myQueue.push(20);
	myQueue.push(30);

	std::cout << "Front element: " << myQueue.front() <<std::endl;
	std::cout << "Back element: " << myQueue.back() << std::endl;
	
	myQueue.pop();

	std::cout << "After popping, front element: " << myQueue.front() << std::endl;
	std::cout << "After popping, back element: " << myQueue.back() << std::endl;

	g3::queue<int> copyQueue(myQueue);

        std::cout << "Copied queue, front element: " << copyQueue.front() << std::endl;
        std::cout << "Copied queue, back element: " << copyQueue.back() << std::endl;
 
        g3::queue<int> moveQueue(std::move(copyQueue));

        std::cout << "Moved queue, front element: " << moveQueue.front() << std::endl;
        std::cout << "Moved queue, back element: " << moveQueue.back() << std::endl;

    return 0;
}
