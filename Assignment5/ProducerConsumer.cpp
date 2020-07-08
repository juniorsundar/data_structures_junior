#include "ProducerConsumer.hpp"
#include <iostream>
using namespace std;

ProducerConsumer::ProducerConsumer() {
  queueEnd = 0;
  queueFront = 0;
}

bool ProducerConsumer::isEmpty() {
  if (queueEnd == queueFront && queue[queueEnd] == "") {
    return true;
  }
  return false;
}

bool ProducerConsumer::isFull() {
  if (queueEnd == queueFront && queue[queueEnd] != "") {
    return true;
  }
  return false;
}

void ProducerConsumer::enqueue(std::string item) {
  if (isFull()) {
    cout << "Queue full, cannot add new item" << endl;
  } else {
    queue[queueEnd] = item;
    queueEnd++;
    queueEnd = queueEnd % SIZE;
    counter++;
  }
}

void ProducerConsumer::dequeue() {
  if (isEmpty()) {
    cout << "Queue empty, cannot dequeue an item" << endl;
  } else {
    queue[queueFront] = "";
    queueFront++;
    queueFront = queueFront % SIZE;
    counter--;
  }
}

std::string ProducerConsumer::peek() {
  if (isEmpty()) {
    cout << "Queue empty, cannot peek" << endl;
    return "";
  } else {
    return queue[queueFront];
  }
}

int ProducerConsumer::queueSize() {
  return counter;
}
