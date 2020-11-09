/**
 * Nick Wright
 * 040911884
 * CST8244
 */

#include "des.h"

int main(void) {

	client_send_t msg_send;
	server_response_t msg_receive;
	pid_t serverpid;
	int coid;

	//On Failure: print usage message and EXIT_FAILURE
	if (argc != 5) {
		//print usage message
		fprintf(stderr,
				"Usage: ./des_inputs <pid of des_display> x y z <enter>\n");
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

		//Prompt User for DES input-event (printf())

		//Get input-event from User (scanf())

		//IF input-event == "ls" THEN

		//Prompt User for person ID

		//Get person ID from User

		//TODO: apply what you know and repeat for "rs"

		//TODO: apply what you know and repeat for "ws", with the notable exception: prompt User for person's weight

		//Send Person object to controller (server); no message from controller is returned to client.

		//IF input-event == "exit" THEN

		//break out of while loop

	}

	//Phase III
	//Call ConnectDetach() to detach from controller's channel
	ConnectDetach(coid);

	exit(EXIT_SUCCESS);
}
