from array import array

def q(rad,kol):
  return 9*rad+kol

def testa(rad,kol,tal,tab):
  for i in range(9):
    if tab[q(rad,i)]==tal:
      return 0
  for i in range(9):
    if tab[q(i,kol)]==tal:
      return 0
  for i in range(rad/3*3,rad/3*3+3,1):
    for j in range(kol/3*3,kol/3*3+3,1):
      if tab[q(i,j)]==tal:
        return 0
  return 1

def skrivut(tab):
  for rad in range(9):
    for kol in range(9):
      print tab[q(rad,kol)],
    print
    
def solve(n,tab):
  if n==81:
    skrivut(tab)
  else:
    i,i1,j1,ok=0,0,0,False
    while i<9 and not ok:
      j=0
      while j<9 and not ok:
        if tab[q(i,j)]==0:
          i1,j1,ok=i,j,True
        j+=1
      i+=1
      for k in range(9):
        if testa(i1,j1,k+1,tab):
          tab[q(i1,j1)]=k+1
          solve(n+1,tab)
          tab[q(i1,j1)]=0
  
def main():
  fil=open("sudoku.txt","r")
  tab=array('I')
  for rad in fil:
    r=rad.split()
    for tal in r:
      tab.append(int(tal))    
  n=0
  for tal in tab:
    if tal!=0:
      n+=1       
  solve(n,tab)        
  
main()  