In your project directory, run:

bash
Copy code
go mod init <module_name>

2. Install the Package
Go modules automatically handle dependencies. When you import a package and run your code or run go mod tidy, Go will automatically download and install the necessary package.

To install "github.com/k0kubun/pp" explicitly, you can run:

bash
Copy code
go get github.com/k0kubun/pp