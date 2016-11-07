data <- iris
#k <- readline("enter number of clusters:")
#k <- as.integer(k)
n <- 150
k <- 3
ck <- n/k
t <- 0
C <- list()
u <- list()
P <- list()
si <- list()
for (i in 1:k) {
  C[[i]] <- iris[(ck*(i - 1)+1):(ck*i),1:2]
  u[[i]] <- runif(k, 0, 1)
  P[[i]] <- 1/k
  si[[i]] <- 1
}
dat <- iris[1:n,1:2]
print("INIT")

repeat {
  t <- t + 1
  w = list()
  # Expectation
  for (i in 1: k) {
    w[[i]] <- dnorm(dat[, 1], mean=u[[i]], sd=si[[i]])*P[[i]]
    d = 0
    for (a in 1:k) {
      d <- d + dnorm(dat[, 1], mean=u[[a]], sd=si[[a]])*P[[a]]
    }
    w[[i]] <- w[[i]] / d
  }
  
  new_u <- u
  new_p <- P
  new_si <- si
  # Maximization
  for (i in 1: k) {
    new_u[[i]] <- sum(w[[i]]*dat)/sum(w[[i]])
    new_si[[i]] <- sum(w[[i]] * (dat - u[[i]])*t(dat-u[[i]]))/sum(w[[i]])
    new_p[[i]] <- sum(w[[i]])/n
  }
  
  err <- 0
  for (i in 1:k) {
    err = err + (u[[i]] - new_u[[i]])^2
  }
  u <- new_u
  P <- new_p
  si <- new_si
  
  if (err[1] < 0.0001) {
    break
  }
}

