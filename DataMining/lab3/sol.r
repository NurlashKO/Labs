D <- iris[, 1]
n <- 150
z <- 0.515
e <- 0.0001
h <- 0.35

F <- function(D, X) {
  res <- 0
  for (x in D) {
    if (x <= X) {
      res = res + 1
    }
  }
  return(res / length(D))
}

f <- function(D, X) {
  return((F(D, X + h/2) - F(D, X - h/2)) / h)
}

K <- function(X) {
  return(1/sqrt(2*pi) * (-exp(X * X / 2.0))) 
}

find_attractor <- function(X) {
  repeat {
    Xp <- X
    s <- 0
    t <- 0
    for (i in 1:n) {
      s <- s + K(X - D[i])*D[i]
      t <- t + K(X - D[i])
    }
    
    X <- s / t
    if (abs(X - Xp) > e) {
      break
    }  
  }
  return(X)
}

xc = NULL
ls = NULL
color = NULL

cnt <- 1
for (i in 1:n) {
  xc[i] <- find_attractor(D[i])
  if (i == 1) {
    ls[cnt] = xc[i]
  }
  if (f(D, xc[i]) >= z) {
    if (abs(ls[cnt] - xc[i]) > e) {
      cnt = cnt + 1;
    }
  }
  ls[cnt] = xc[i]
  color[i] = cnt
}
plot(D, col=color)
# Kernel Density Plot
d <- density(D) # returns the density data 
plot(d) # plots the results
# Kernel Density Plot
d <- density(xc) # returns the density data 
plot(d) # plots the results
#hist(D)
#hist(xc)

