# Test Files

[./xmlsec/](./xmlsec/) contains the original files from the libxmlsec examples


## RSA Files

```
$ openssl genrsa -out rsakey.pem 512
$ openssl rsa -in rsakey.pem -pubout -out rsapub.pem
$ openssl req -new -x509 -key rsakey.pem -out rsacert.pem -days 36500 -sha1
$ openssl pkcs12 -export -inkey rsakey.pem -in rsacert.pem -out rsacert.pfx
```
The _rsacert.pfx_ file was created using "1234" as password.
