#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Customer {
public:

	int in_time;
	int order_time; // will be 1 to 6 min.
	int out_time;
	Customer *next;

	Customer(int t) {
		in_time = t;
		order_time = rand() % 6 + 1;
		out_time = 0;
		next = NULL;
	}
};

class queue {
public:
	int length;
	Customer *head, *tail, *tail2;

	queue() {
		head = NULL;
		tail = NULL;
		tail2 = NULL;
		length = 0;
	}

	//enqueue this new customer
	void enqueue(int t) {
		int service_time = 0;
		Customer *temp = new Customer(t);
		Customer *temp2 = new Customer(t);
		temp->order_time = rand() % 6 + 1;
		temp->in_time = t;

		if (head == NULL) {
			head = temp;
			tail = temp;
			tail2 = temp;
			length++;
		}
		else if (length == 1) {
			temp->next = head;
			tail = temp;
			head = temp;
			length++;
		}
		else if (length == 2) {
			temp->next = head;
			head = temp;
			length++;
		}
		else {
			temp->next = head;
			head = temp;
			length++;
		}
	}

	//deletes very last item in queue
	void dequeue(int current_time) {
		Customer *temp = head;
		Customer *temp2 = head;
		Customer *follow = head, *chase = head;

		if (head == NULL) {
			cout << "Nothing to delete, empty queue!" << endl;
		}
		else if (head->next == NULL) {
			cout << "About to delete: " << head->in_time << endl;
			delete head;
			head = NULL;
			tail = NULL;
			tail2 = NULL;
			length--;
		}
		else if (length == 2) {
			cout << "About to delete: " << tail2->in_time << endl;
			tail2 = head;
			head->next = NULL;
			length--;
		}
		else {
			while (chase->next->next != NULL) {
				follow = chase;
				chase = chase->next;
			}

			cout << "About to delete: " << tail2->in_time << endl;
			tail = follow;
			tail2 = chase;
			chase->next = NULL;
			length--;
		}
	}

	//deletes second to last item in queue
	void dequeue2(int current_time) {
		Customer *temp = head;
		Customer *temp2 = head;
		Customer *follow = head, *chase = head;

		if (head == NULL) {
			cout << "Nothing to delete, empty queue!" << endl;
		}
		else if (head->next == NULL) {
			delete head;
			head = NULL;
			tail = NULL;
			tail2 = NULL;
			length--;
		}
		else if (length == 2) {
			delete head;
			head = tail = tail2;
			length--;
		}
		else {
			while (chase->next->next != NULL) {
				follow = chase;
				chase = chase->next;
			}
			follow->next = tail2;
			delete chase;
			tail = follow;
			length--;
		}
	}

	void dequeuecheck() {
		if (head == NULL) {}
		else if (head->next == NULL) {
			tail->order_time--;
		}
		else {
			tail->order_time--;
			tail2->order_time--;
		}
	}

};

int main() {
	queue burgerJoint;

	int current_time = 0;
	int service_time = 0;
	int wait_time = 0;
	int num_served = 0;
	int queue_length = 0;

	int total_service_time = 0;
	int total_wait_time = 0;
	int total_queue_length = 0;
	int randNum;

	srand(time(NULL));
	while (current_time < 1020) {
		randNum = rand() % 100 + 1;
		if (current_time > 0 && current_time <= 120) {

			if (randNum <= 30) {
				burgerJoint.enqueue(current_time);
				num_served++;
				queue_length++;
				total_queue_length += queue_length;
			}
			if (burgerJoint.tail == NULL || burgerJoint.tail2 == NULL) {
				cout << "null" << endl;
			}

			else if (burgerJoint.tail->order_time <= 0 && burgerJoint.tail2->order_time <= 0) {
				service_time = current_time - burgerJoint.tail->in_time;
				wait_time = service_time - burgerJoint.tail->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;
				service_time = current_time - burgerJoint.tail2->in_time;
				wait_time = service_time - burgerJoint.tail2->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;

				queue_length--;
				total_queue_length += queue_length;
				burgerJoint.dequeue(current_time);
				burgerJoint.dequeue(current_time);

			}

			else if (burgerJoint.tail->order_time <= 0) {
				service_time = current_time - burgerJoint.tail->in_time;
				wait_time = service_time - burgerJoint.tail->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;
				queue_length--;
				total_queue_length += queue_length;
				burgerJoint.dequeue2(current_time);

			}

			else if (burgerJoint.tail2->order_time <= 0) {
				service_time = current_time - burgerJoint.tail->in_time;
				wait_time = service_time - burgerJoint.tail->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;
				queue_length--;
				total_queue_length += queue_length;
				burgerJoint.dequeue(current_time);

			}
			else {
				burgerJoint.dequeuecheck();
			}

		}

		else if (current_time > 120 && current_time <= 210) {
			if (randNum <= 10) {
				burgerJoint.enqueue(current_time);
				num_served++;
				queue_length++;
				total_queue_length += queue_length;
			}
			if (burgerJoint.tail == NULL || burgerJoint.tail2 == NULL) {
				cout << "null" << endl;
			}

			else if (burgerJoint.tail->order_time <= 0 && burgerJoint.tail2->order_time <= 0) {
				service_time = current_time - burgerJoint.tail->in_time;
				wait_time = service_time - burgerJoint.tail->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;
				service_time = current_time - burgerJoint.tail2->in_time;
				wait_time = service_time - burgerJoint.tail2->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;

				queue_length--;
				queue_length--;
				total_queue_length += queue_length;
				burgerJoint.dequeue(current_time);
				burgerJoint.dequeue(current_time);

			}

			else if (burgerJoint.tail->order_time <= 0) {
				service_time = current_time - burgerJoint.tail->in_time;
				wait_time = service_time - burgerJoint.tail->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;
				queue_length--;
				total_queue_length += queue_length;
				burgerJoint.dequeue2(current_time);

			}

			else if (burgerJoint.tail2->order_time <= 0) {
				service_time = current_time - burgerJoint.tail->in_time;
				cout << "Found the service time for 2" << endl;
				wait_time = service_time - burgerJoint.tail->order_time;
				cout << "Current wait time is" << wait_time << endl;
				total_service_time += service_time;
				total_wait_time += wait_time;
				queue_length--;
				total_queue_length += queue_length;
				burgerJoint.dequeue(current_time);

			}
			else {
				burgerJoint.dequeuecheck();
			}
		}

		else if (current_time > 210 && current_time <= 330) {
			if (randNum <= 40) {
				burgerJoint.enqueue(current_time);
				num_served++;
				queue_length++;
				total_queue_length += queue_length;
			}
			if (burgerJoint.tail == NULL || burgerJoint.tail2 == NULL) {
				cout << "null" << endl;
			}

			else if (burgerJoint.tail->order_time <= 0 && burgerJoint.tail2->order_time <= 0) {
				service_time = current_time - burgerJoint.tail->in_time;
				cout << "Found the service time for 1 and 2" << endl;
				wait_time = service_time - burgerJoint.tail->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;
				service_time = current_time - burgerJoint.tail2->in_time;
				wait_time = service_time - burgerJoint.tail2->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;

				queue_length--;
				queue_length--;
				total_queue_length += queue_length;
				burgerJoint.dequeue(current_time);
				burgerJoint.dequeue(current_time);

			}

			else if (burgerJoint.tail->order_time <= 0) {
				service_time = current_time - burgerJoint.tail->in_time;
				wait_time = service_time - burgerJoint.tail->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;
				queue_length--;
				total_queue_length += queue_length;
				burgerJoint.dequeue2(current_time);
			}

			else if (burgerJoint.tail2->order_time <= 0) {
				service_time = current_time - burgerJoint.tail->in_time;
				wait_time = service_time - burgerJoint.tail->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;
				queue_length--;
				total_queue_length += queue_length;
				burgerJoint.dequeue(current_time);
			}
			else {
				cout << burgerJoint.tail->order_time << endl;
				cout << burgerJoint.tail2->order_time << endl;
				burgerJoint.dequeuecheck();
			}
		}

		else if (current_time > 330 && current_time <= 570) {
			if (randNum <= 10) {
				burgerJoint.enqueue(current_time);
				num_served++;
				queue_length++;
				total_queue_length += queue_length;
			}
			if (burgerJoint.tail == NULL || burgerJoint.tail2 == NULL) {
				cout << "null" << endl;
			}

			else if (burgerJoint.tail->order_time <= 0 && burgerJoint.tail2->order_time <= 0) {
				service_time = current_time - burgerJoint.tail->in_time;
				cout << "Found the service time for 1 and 2" << endl;
				wait_time = service_time - burgerJoint.tail->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;
				service_time = current_time - burgerJoint.tail2->in_time;
				wait_time = service_time - burgerJoint.tail2->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;

				queue_length--;
				queue_length--;
				total_queue_length += queue_length;
				burgerJoint.dequeue(current_time);
				burgerJoint.dequeue(current_time);

			}

			else if (burgerJoint.tail->order_time <= 0) {
				service_time = current_time - burgerJoint.tail->in_time;
				cout << "Found the service time for 1" << endl;
				wait_time = service_time - burgerJoint.tail->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;
				queue_length--;
				total_queue_length += queue_length;
				burgerJoint.dequeue2(current_time);

			}

			else if (burgerJoint.tail2->order_time <= 0) {
				service_time = current_time - burgerJoint.tail->in_time;
				cout << "Found the service time for 2" << endl;
				wait_time = service_time - burgerJoint.tail->order_time;
				cout << "Current wait time is" << wait_time << endl;
				total_service_time += service_time;
				total_wait_time += wait_time;
				queue_length--;
				total_queue_length += queue_length;
				burgerJoint.dequeue(current_time);

			}
			else {
				burgerJoint.dequeuecheck();

			}
		}

		else if (current_time > 570 && current_time <= 720) {
			if (randNum <= 25) {
				burgerJoint.enqueue(current_time);
				cout << "Someone was enqueued successfully" << endl;
				num_served++;
				queue_length++;
				total_queue_length += queue_length;
			}
			if (burgerJoint.tail == NULL || burgerJoint.tail2 == NULL) {
				cout << "null" << endl;
			}

			else if (burgerJoint.tail->order_time <= 0 && burgerJoint.tail2->order_time <= 0) {
				service_time = current_time - burgerJoint.tail->in_time;
				cout << "Found the service time for 1 and 2" << endl;
				wait_time = service_time - burgerJoint.tail->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;
				service_time = current_time - burgerJoint.tail2->in_time;
				wait_time = service_time - burgerJoint.tail2->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;

				queue_length--;
				queue_length--;
				total_queue_length += queue_length;
				burgerJoint.dequeue(current_time);
				burgerJoint.dequeue(current_time);

			}

			else if (burgerJoint.tail->order_time <= 0) {
				service_time = current_time - burgerJoint.tail->in_time;
				cout << "Found the service time for 1" << endl;
				wait_time = service_time - burgerJoint.tail->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;
				queue_length--;
				total_queue_length += queue_length;
				burgerJoint.dequeue2(current_time);

			}

			else if (burgerJoint.tail2->order_time <= 0) {
				service_time = current_time - burgerJoint.tail->in_time;
				wait_time = service_time - burgerJoint.tail->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;
				queue_length--;
				total_queue_length += queue_length;
				burgerJoint.dequeue(current_time);

			}
			else {
				burgerJoint.dequeuecheck();

			}
		}

		else if (current_time > 720 && current_time <= 900) {
			if (randNum <= 20) {
				burgerJoint.enqueue(current_time);
				cout << "Someone was enqueued successfully" << endl;
				num_served++;
				queue_length++;
				total_queue_length += queue_length;
			}
			if (burgerJoint.tail == NULL || burgerJoint.tail2 == NULL) {
				cout << "null" << endl;
			}

			else if (burgerJoint.tail->order_time <= 0 && burgerJoint.tail2->order_time <= 0) {
				service_time = current_time - burgerJoint.tail->in_time;
				wait_time = service_time - burgerJoint.tail->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;
				service_time = current_time - burgerJoint.tail2->in_time;
				wait_time = service_time - burgerJoint.tail2->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;

				queue_length--;
				queue_length--;
				total_queue_length += queue_length;
				burgerJoint.dequeue(current_time);
				burgerJoint.dequeue(current_time);

			}

			else if (burgerJoint.tail->order_time <= 0) {
				service_time = current_time - burgerJoint.tail->in_time;
				wait_time = service_time - burgerJoint.tail->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;
				queue_length--;
				total_queue_length += queue_length;
				burgerJoint.dequeue2(current_time);

			}

			else if (burgerJoint.tail2->order_time <= 0) {
				service_time = current_time - burgerJoint.tail->in_time;
				wait_time = service_time - burgerJoint.tail->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;
				queue_length--;
				total_queue_length += queue_length;
				burgerJoint.dequeue(current_time);

			}
			else {
				burgerJoint.dequeuecheck();

			}
		}

		else if (current_time > 900 && current_time <= 1020) {
			if (randNum <= 10) {
				burgerJoint.enqueue(current_time);
				num_served++;
				queue_length++;
				total_queue_length += queue_length;
			}
			if (burgerJoint.tail == NULL || burgerJoint.tail2 == NULL) {
				cout << "null" << endl;
			}

			else if (burgerJoint.tail->order_time <= 0 && burgerJoint.tail2->order_time <= 0) {
				service_time = current_time - burgerJoint.tail->in_time;
				wait_time = service_time - burgerJoint.tail->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;
				service_time = current_time - burgerJoint.tail2->in_time;
				wait_time = service_time - burgerJoint.tail2->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;

				queue_length--;
				queue_length--;
				total_queue_length += queue_length;
				burgerJoint.dequeue(current_time);
				burgerJoint.dequeue(current_time);

			}

			else if (burgerJoint.tail->order_time <= 0) {
				service_time = current_time - burgerJoint.tail->in_time;
				wait_time = service_time - burgerJoint.tail->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;
				queue_length--;
				total_queue_length += queue_length;
				burgerJoint.dequeue2(current_time);

			}

			else if (burgerJoint.tail2->order_time <= 0) {
				service_time = current_time - burgerJoint.tail->in_time;
				wait_time = service_time - burgerJoint.tail->order_time;
				total_service_time += service_time;
				total_wait_time += wait_time;
				queue_length--;
				total_queue_length += queue_length;
				burgerJoint.dequeue(current_time);

			}
			else {
				burgerJoint.dequeuecheck();

			}
		}
		current_time++;
	}
	cout << "Average wait time: " << total_wait_time / num_served << endl;
	cout << "Average service time: " << total_service_time / num_served << endl;
	cout << "Average queue length: " << -total_queue_length / 1020 << endl;
	cout << "Best case: 8 am when there is no line. " << "Worst case:" << endl;

	system("pause");
	return 1;
}