//Cwiczenie 1
#include <iostream>

auto main() -> int
{
	int* ap = reinterpret_cast<int*>(0xdeadbeef);
        std::cout << ap << "\n";
	std::cout << *ap << "\n";

	return 0;    
}

//Cwiczenie 2
#include <iostream>
#include <sys/types.h>
#include <unistd.h>

auto main() -> int 
{
	auto x = fork();
	if(x == 0)
       	{
		std::cout << "ppid: " << getppid() << "\n";
	} else {
		std::cout << "inny: " << x << "\n";
	}

	return 0;
}

//Cwiczenie 3
#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>

auto execute(std::vector<std::string> args) -> int
{
        auto argv = std::vector<char*>{};
	for (auto const& each : args)
	{
	        argv.push_back(const_cast<char*>(each.c_str()));
	}
	argv.push_back(nullptr);
	
	auto env = std::vector<char*>{};
	env.push_back(nullptr);
	
	execve(argv[0], argv.data(), env.data());
	exit(EXIT_FAILURE);
}

auto main(int argc, char* argv[]) -> int
{ 
	auto args = std::vector<std::string>{};
	for (auto i = 1; i < argc; ++i)
	{
	        args.push_back(argv[i]);
	}
	
	execute(args);
	
	return 0;
}

//Cwiczenie 4
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <vector>
#include <string>

auto execute(std::vector<std::string> args) -> int
{
        auto argv = std::vector<char*>{};
	for (auto const& each : args)
	{
	        argv.push_back(const_cast<char*>(each.c_str()));
	}
	argv.push_back(nullptr);
	
	auto env = std::vector<char*>{};
	env.push_back(nullptr);
	
	execve(argv[0], argv.data(), env.data());
	exit(EXIT_FAILURE);
}

auto sigchld_handler(int signo) -> void
{
         std::cout << "got SIGCHLD\n";
	 
	 auto status = int{0};
	 auto child = waitpid{-1, &status, 0};
	 if (WIFEXITED(status))
	 {
	         std::cout
	             << "child " << child
		     << " exited normally with " << WEXITSTATUS(status) << "\n";
                 exit(0);
	 }
}

auto main(int argc, char* argv[]) -> int
{ 
	auto const child = fork();
	if (child == 0)
	{
	        execute({ "/bin/sleep", "3" });
	}
	std::cout << "spawned child " << child << "\n";
	
	signal(SIGCHLD, sigchld_handler);
	
	while (true);
	
	return 0;
}

//Cwiczenie 7
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

auto handler_sigusr1(int signum) -> void
{
	char msg[] = "Signal ?? SIGUSR1\n";
	msg[7] = (signum / 10) + '0';
	msg[8] = (signum % 10) + '0';
	auto ret = write(2, msg, sizeof(msg) - 1);
	std::cout << ret;
}
auto main() -> int
{
	struct sigaction action;

	action.sa_flags = 0;
	action.sa_handler = handler_sigusr1;
	sigemptyset(&action.sa_mask);

	sigaction(SIGUSR1, &action, NULL);

	return 0;
}
