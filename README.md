# HTTP Parser in C++

A small C++ project for learning and practicing basic parsing techniques.

## Current Features

- Reads an HTTP request from a text file
- Parses the request line:
  - Method
  - Path
  - HTTP version
- Parses HTTP headers
- Stores headers as key-value pairs
- Preserves header order

## Example Input

```text
GET /hello.htm HTTP/1.1
User-Agent: Mozilla/4.0
Host: www.example.com
Accept-Language: en-us
Connection: Keep-Alive
```

## Planned Improvements

- Detect malformed headers
- Validate the request line
- Parse the HTTP body
- Handle `Content-Length`
- Refactor parsing logic into separate functions
- Add fuzz testing

## Purpose

This project is mainly intended as a learning exercise for C++, HTTP parsing, and later fuzz testing.