BEGIN{
FS=":"
tot_sal=0
p1_t=0
p2_t=0
p3_t=0
count=0
}
{
count++
n[count]=$1
s[count]=$2+$3+$4
tot+=s[count]
p1_t+=$2
P2_t+=$3
p3_t+=$4
}
END{
print tot
print p1_t
print p2_t
print p3_t
if(p1_t>p2_t && p1_t>p3_t){
print "p1 is highest"
}
else if(p2_t>p3_t){
print "p2 is highest"
}
else{
print "p3 is highest"
}
b=s[count]
w=s[count]
b_m=n[count]
w_m=n[count]
while(count>0){
if(s[count]>=b){
b=s[count]
b_m=n[count]
}
if(s[count]<=w){
w=s[count]
w_m=n[count]
}
count--
}
print b
print w
}
