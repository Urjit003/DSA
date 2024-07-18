awk
BEGIN{
FS="-"
tot_male=0
tot_female=0
tot_pass=0
tot_fail=0
}
{
sno=$1
sname=$2
gen=$3
m1=$4
m2=$5
m3=$6
tot_mark=m1+m2+m3
per=tot_mark/3
if(gen=="M"){
tot_male++
}else if(gen=="F"){
tot_female++
}
if(m1>=40 && m2>=40 && m3>=40){
tot_pass++
}
else{
tot_fail++
}
print "Stu no" sno
print sname
print gen
print tot_mark
print per
print ""
}
END{
print tot_male
print tot_female
print tot_pass
print_fail
}
