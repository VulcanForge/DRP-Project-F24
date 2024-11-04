n1 <- 597158248165169644887070147581847514809 #prime
n2 <- 597158248165169644887070147581847514621 #composite

n <- n2
g <- function(x,n) {
  (x*x + 1)%%n;
}

gcd <- function(a,b) {
  abs(a)
  abs(b)
  i <- a
  while (i >0) {
    if ((a%%i==0)&&(b%%i==0)) {
      return(i)
    }
    i <- i - 1
  }
  return(1)
}


t <- 2
h <- 2
d <- 1

t <- g(t,n)
h <- g(g(h,n),n)
d <- gcd(t-h, n)

while (d == 1) {
  if (t == h) {
    print("maybe it's prime")
    break
  }
  if (d == 1) {
    t <- g(t,n)
    h <- g(g(h,n),n)
    d <- gcd(t-h,n)
  }
  m<- n %% d
  if ((d>1) && (m == 0)) {
    print(paste("factor is ", d))
  }
}