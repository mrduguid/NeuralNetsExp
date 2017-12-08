//don't forget to comment!!

/* 
 * both types of comment
 */
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


struct node_t {
	//bool state;
	float value;
	float threashold;
};

struct synapse_t {
	float weight;
	node_t * inNode;
	node_t * outNode;
};

int addition (int a, int b)
{
	return a + b;
}

float link (float a, float weight)
{
	return a * weight;
}

float node (float a, float b)
{
	return a * b;
}

int main()
{
	string helloString;
	int aNumber = 1;
	int * aNumberPointer;
	int i, j;
	node_t node1;
	node_t node2;
	node_t inputNodes[10];
	node_t midNodes[10];
	node_t exitNodes[10];
	//node_t tempNode;
	synapse_t link1;
	synapse_t links[60];
	float tempCode;
	
	srand (time(NULL));
	
	//setup input nodes in the array
	for (i = 0; i<10; i++)
	{
		tempCode = rand() % 100;
		inputNodes[i].value = tempCode/100;
		inputNodes[i].threashold = 0.5;
	}
	
	//setup mid nodes (may not be needed)
	for (i = 0; i<10; i++)
	{
		midNodes[i].value = 0;
		midNodes[i].threashold = 0.5;
	}
	
	//setup exit nodes (may not be needed)
	for (i = 0; i<10; i++)
	{
		exitNodes[i].value = 0;
		exitNodes[i].threashold = 0.5;
	}
	i = rand() % 10;
	/*
	 * Time to link the nodes together
	 */
	 j = 0;
	 for (i = 0; i<30; i++)
	 {
		 if (i%10 == 0 && i > 1)
		 {
			 j++;
		 }
		 links[i].inNode = &inputNodes[i%10];
		 links[i].outNode = &midNodes[(i+j)%10];
		 links[i].weight = 0.25;
		 cout << "Done link: " << i << " " << links[i].weight << " : " << (*links[i].inNode).value << " : " << (*links[i].outNode).value << "\n";
	 }
	 
	 j = 0;
	 for (i = 30; i<60; i++)
	 {
		 if (i%10 == 0 && i > 31)
		 {
			 j++;
		 }
		 links[i].inNode = &midNodes[i%10];
		 links[i].outNode = &exitNodes[(i+j)%10];
		 links[i].weight = 0.25;
		 cout << "Done link: " << i << " " << links[i].weight << " : " << (*links[i].inNode).value << " : " << (*links[i].outNode).value << "\n";

	 }
	 
	 //time to update the nodes
	for (i = 0; i<60; i++)
	{	
		if ((*links[i].inNode).value > (*links[i].inNode).threashold)
		{
			//cout << "node1.state = true\n";
			(*links[i].outNode).value += (*links[i].inNode).value * links[i].weight;
			cout << "Node value: "<< (*links[i].outNode).value << "\n";
		} else {
			//cout << "node1.state = false\n";
		}
	}
	
	cout <<"inputNodes[0] = "<< inputNodes[0].value<< "\n";
	cout <<"midNodes[0] = "<< midNodes[0].value<< "\n";
	cout <<"outputNodes[0] = "<< exitNodes[0].value<< "\n";
	for (i=0; i<10; i++)
	{
		cout << "exitNode[" << i << "]: " << exitNodes[i].value << "\n";
	}
	//node1.state = true;
	node1.value = 0.8;
	node1.threashold = 0.7;
	
	//node2.state = false;
	node2.value = 0.0;
	node2.threashold = 0.7;
	
	link1.weight = 0.5;
	link1.inNode = &node1;
	link1.outNode = &node2;
	
	//tempNode = *link1.inNode;
	//cout << tempNode.state << "\n";
	//cout << (*link1.inNode).state << "\n";
	if ((*link1.inNode).value > (*link1.inNode).threashold)
	{
		cout << "node1.state = true\n";
	} else {
		cout << "node1.state = false\n";
	}
	// This is where I will experiment with passing messages along the synapses
	if ((*link1.inNode).value > (*link1.inNode).threashold)
	{
		cout << "node1.state = true\n";
		(*link1.outNode).value = (*link1.inNode).value * link1.weight;
		cout << "Node2 value: "<< node2.value << "\n";
	} else {
		cout << "node1.state = false\n";
	}
	
	cout << aNumber << "\n";
	aNumberPointer = &aNumber;
	cout << aNumberPointer << "\n";
	helloString = "Hello all of you!";
	cout << helloString << "\n";
	//without using namespace std would be std::cout . . .
	cout << "Hello World!\n";
	cout << "I am a C++ Program\n";
	cout << addition(2, 5) << endl;
}
