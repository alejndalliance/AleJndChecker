AleJndChecker
==========

`AleJndChecker` is a service checker used to get the status (up/down) of the services from vulnerable VMs. The status is then be displayed on the scoreboard.

#### Usage

Install the dependencies

*NOTE* : Make sure to set the `INTERFACE` in file `get_flag.cpp` to the configured interface name. Then update the `CHECKER_GATEWAY` and `key` in `checker.cpp`. Some modifications is needed at [line 36](https://github.com/alejndalliance/AleJndChecker/blob/master/checker.cpp#L36) to add specific service name. The checker should be setup using a [Supervisord](http://supervisord.org/) or any other startup tools.

```Bash
$ sudo apt-get install libjsoncpp-dev libcurl4-openssl-dev libssl-dev
$ make all
$ ./checker
```
