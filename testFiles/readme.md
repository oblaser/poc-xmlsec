# Test Files

The directory [xmlsec](./xmlsec/) contains the original files from the libxmlsec examples

[xml-01_signed_with_public-key.xml](./xml-01_signed_with_public-key.xml) is valid in [chilkat](https://tools.chilkat.io/xmlDsigVerify.cshtml).

## RSA Files

```
$ openssl genrsa -out rsakey.pem 512
$ openssl rsa -in rsakey.pem -pubout -out rsapub.pem
$ openssl req -new -x509 -key rsakey.pem -out rsacert.pem -days 36500 -sha1
$ openssl pkcs12 -export -inkey rsakey.pem -in rsacert.pem -out rsacert.pfx
```
The _rsacert.pfx_ file was created using "1234" as password.
