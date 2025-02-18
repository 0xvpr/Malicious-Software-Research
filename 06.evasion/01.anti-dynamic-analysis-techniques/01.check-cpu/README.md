# Check CPU
Credit to [0xPat](https://0xpat.github.io) (inspirer of the moniker 0xvpr)

### Detecting virtualized environment
Both sandboxes and analyst’s virtualized OSes usually can’t 100% accurately  
emulate actual execution environment (like typical user workstation).  
Virtualized environments have limited resources (corresponding device names  
can also provide useful information), may have VM-specific tools and drivers  
installed, often look like a fresh Windows installation and sometimes use  
hardcoded user or computer names. We can take advantage of that.

### Hardware resources
The main problem are limited resources - a sandbox may not be able to run long  
and consuming simulations in parallel so is often restricts resources commited  
and time allocated for a single instance. Regular VM boxes used by analysts are  
also subject for same constraints - they often have their resources limited.

Typical user workstation has a processor with at least 2 cores, a minimum of  
2 GB of RAM and a 100 GB hard drive. We can verify if the environment our  
malicious application is being executed in is a subject to these constrains: