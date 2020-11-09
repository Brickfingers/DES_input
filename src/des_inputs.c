/**
 * Nick Wright & Kevin Luu
 * 040911884 & 040905303
 * CST8244
 */

#include "../../des_controller/src/des.h"

int main(void) {

	Person person;

	client_send_t msg_send;
	server_response_t msg_receive;
	pid_t serverpid;
	int coid;

	//On Failure: print usage message and EXIT_FAILURE
	if (argc != 2) {
		//print usage message
		fprintf(stderr,
				"Usage: ./des_inputs <pid of des_display> <enter>\n");
		exit(EXIT_FAILURE);
	}

	//Phase I
	//Get controller's PID from command-line arguments.
	serverpid = atoi(argv[1]);

	//Call ConnectAttach() to attach to controller's channel
	coid = ConnectAttach(ND_LOCAL_NODE, serverpid, 1, _NTO_SIDE_CHANNEL, 0);

	//On Failure: print error message and EXIT_FAILURE
	if (coid == -1) {
		fprintf(stderr, "ConnectAttach had an error\n");
		exit(EXIT_FAILURE);
	}

	//Phase II
	while( TRUE ){
		char input[64];
		//Prompt User for DES input-event (printf())
		puts("Enter the event type (ls = left scan, rs = right scan, ws = weight scale, lo = left open, ro = right open, lc = left closed, rs = right closed, gru = guard right unlock, grl = guard right lock, gll = guard left lock, glu = guard left unlock, exit = exit programs)\n");
		//Get input-event from User (scanf())
		scanf("%s", input);
		//IF input-event == "ls" THEN
		if (strcmp(&input, inMessage[0]))
		{
			//Prompt User for person ID
			printf("Enter the person's ID: \n");
			//Get person ID from User
			scanf("%d", &person.id);

		}
		//apply what you know and repeat for "rs"
		if (strcmp(&input, inMessage[1]))
		{
			//Prompt User for person ID
			printf("Enter the person's ID: \n");
			//Get person ID from User
			scanf("%d", &person.id);

		}
		//apply what you know and repeat for "ws", with the notable exception: prompt User for person's weight
		if (strcmp(&input, inMessage[6]))
		{
			//Prompt User for person ID
			printf("Enter the person's weight: \n");
			//Get person ID from User
			scanf("%d", &person.weight);

		}
		//Send Person object to controller (server); no message from controller is returned to client.

		//IF input-event == "exit" THEN
		if (strcmp(&input, inMessage[11]))
		{
			//Prompt User for person ID
			printf("Exiting \n");
			//TODO send message to controller without person?
			//break out of while loop
			break;
		}
		//go again they didn't type anything acceptable
	}

	//Phase III
	//Call ConnectDetach() to detach from controller's channel
	ConnectDetach(coid);
	exit(EXIT_SUCCESS);
}
