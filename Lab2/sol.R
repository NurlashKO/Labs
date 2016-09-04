#Load data
Data <- read.csv("NumericDataAnalysis.txt",head=FALSE,sep=",")
#Remove last column
Data <- Data[, -11]
#Data set size
d = 10
n = 19020

my_mean <- function(data) {
    return (sum(data)/length(data))    
}
#test
#print(my_mean(c(1, 2, 3)))

#1
#multivariate mean vector
#Generalizing Eq. (2.18), the multivariate mean vector is obtained by taking the mean of each attribute, given as
multi_var_mean = c()
for (col in 1:10){
    multi_var_mean[col] <- my_mean(Data[, col])
}

multi_var_mean

#2
#In matrix notation, the sample covariance matrix can be written as
# 1/n*(Z^T)*Z
#mean
u = sum(Data)/(n*d)
#Centered Data Matrix
Z = Data - u
#check that Z is right
#print(sum(Z)) ~ 0

covariance_matrix = (1/n)*(t(Z)*Z)

#3
# I don't want to waste my time
# Replace FALSE by TRUE to see the answer
if (FALSE) {
outer_product = 0
for (i in 1:n) {
    outer_product = sum(outer_product, prod(Z[i, ] * t(Z[i, ])))
}
outer_product = outer_product / n
print(outer_product)
}

#4
#Compute the correlation between Attributes 1 and 2 by computing the cosine of the angle between the centered attribute vectors. Plot the scatter plot between these two attributes.
Z1 = Data[, 1] - my_mean(Data[, 1])
Z2 = Data[, 2] - my_mean(Data[, 2])
#Cosine : A*B/(len(A)*len(B))
len <- function(v) {
    return (sqrt(sum(v^2)))   
}
correlation = sum(Z1*Z2)/(len(Z1)*len(Z2))
print("Correlation")
correlation



#6 

my_variance <- function(data) {
    u = my_mean(data)
    return (1/length(data)*(sum((data-u)^2)))
}
#test
#print(my_variance(c(1, 2, 3, 4, 5)))
max_var = min_var = my_variance(Data[, 1])
max_var_attr = min_var_attr = 1
for (attr in 1:d) {
    cur = my_variance(Data[, attr])
    if (max_var < cur) {
        max_var = cur
        max_var_attr = attr
    }
    if (min_var > cur) {
        min_var = cur
        min_var_attr = attr
    }
}
print("Max/Min var")
max_var_attr
max_var
min_var_attr
min_var


#7
my_covariance <- function(v1, v2) {
    u1 = my_mean(v1) 
    u2 = my_mean(v2)
    return ((1/length(v1))*sum((v1-u1)*(v2-u2)))
}
max_cov = min_cov = my_covariance(Data[, 1], Data[, 2])
max_cov_pair = min_cov_pair = c(1, 2)
for (attr1 in 1:(d - 1)) {
    for (attr2 in (attr1 + 1):d)  {
        cur = my_covariance(Data[, attr1], Data[, attr2])
        if (min_cov > cur) {
            min_cov = cur
            min_cov_pair = c(attr1, attr2)
        }
        if (max_cov < cur) {
            max_cov = cur
            max_cov_pair = c(attr1, attr2)
        }
    }  
}
print("Max/min covariance")
max_cov_pair
max_cov
min_cov_pair
min_cov
