import sys
input = sys.stdin.readline

PetrSU = [2006]
ITMO = [1995,1998,1999,2001,2002,2003,2004,2005,2006,2009,2010,2011,2012,2014,2015,2016,2017,2019]
SPbSU = [1996,1997,2000,2007,2008,2013,2018]

y = int(input())
if y in PetrSU:
    print("PetrSU, ", end='')
if y in ITMO:
    print("ITMO")
if y in SPbSU:
    print("SPbSU")