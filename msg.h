// Provides a library of messages and serial wrapper

class Msg {

	public:

		Msg();

		void write();
		void read();

	private:

		/*
		this will be the id negoitate. if my id is 1, 
		then when i write, it will be 1:m:msg, where m is the recipient
		intended and msg is the message. 

		when there is a read, and it looks m:1:msg. again
		where m is the sender, 1 is me (assuming i am 1)
		*/
		int id;

		/*
		currently while in dev, i believe
		I will use prefix of 0 to negotitate an
		id, so message will be 0:n, where n is an icremental
		id starting at 1

		I will do a back off method. this means I will 
		postfix a random msg message on it. this way when I read,
		if the message that comes to me is 1:0:<not-my-message>, 
		I know that was not intended for me. so I will set a random
		backoff. It it comes back as 1:0:<my-message>, I know someone
		is already 1, so I will increment to 0:2:<my-message>, and so
		on until I have no message come back in say 5 reads and delays
		*/
		int _negotiate();
}