# Tests

#### using the original examples
- [Case 1](#case-1)
- [Case 2](#case-2)
- [Case 3](#case-3)
- [Case 4](#case-4)

Using my own files "testFiles/xml-01_signed.xml", "testFiles/xml-01_signed_with_public-key.xml" and "testFiles/rsapub.pem" gives the same results.

## Case 1
verify1 example
```
arg 0    poc-xmlsec\build\vs\Debug\poc-xmlsec.exe
arg 1    ../../testFiles/xmlsec/sign1-res.xml
arg 2    ../../testFiles/xmlsec/rsapub.pem
==================================
func=xmlSecDSigCtxProcessSignatureNode:file=..\src\xmldsig.c:line=465:obj=unknown:subj=dsigCtx->c14nMethod == NULL:error=100:assertion:
func=xmlSecDSigCtxVerify:file=..\src\xmldsig.c:line=366:obj=unknown:subj=xmlSecDSigCtxSigantureProcessNode:error=1:xmlsec library function failed:
Error: signature verify
===============
return -1
```

## Case 2
verify1 example
```
arg 0    poc-xmlsec\build\vs\Debug\poc-xmlsec.exe
arg 1    ../../testFiles/xmlsec/sign2-res.xml
arg 2    ../../testFiles/xmlsec/rsapub.pem
==================================
func=xmlSecDSigCtxProcessSignatureNode:file=..\src\xmldsig.c:line=465:obj=unknown:subj=dsigCtx->c14nMethod == NULL:error=100:assertion:
func=xmlSecDSigCtxVerify:file=..\src\xmldsig.c:line=366:obj=unknown:subj=xmlSecDSigCtxSigantureProcessNode:error=1:xmlsec library function failed:
Error: signature verify
===============
return -1
```

## Case 3
verify2 example
```
arg 0    poc-xmlsec\build\vs\Debug\poc-xmlsec.exe
arg 1    ../../testFiles/xmlsec/sign1-res.xml
arg 2    ../../testFiles/xmlsec/rsapub.pem
==================================
Signature is INVALID
===============
return 0
```

## Case 4
verify2 example
```
arg 0    poc-xmlsec\build\vs\Debug\poc-xmlsec.exe
arg 1    ../../testFiles/xmlsec/sign2-res.xml
arg 2    ../../testFiles/xmlsec/rsapub.pem
==================================
Signature is INVALID
===============
return 0
```
