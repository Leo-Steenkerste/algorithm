#!/usr/bin/python3





 s = '12345678'
 t = iter(s)
 '-'.join(a+b for a,b in zip(t, t))