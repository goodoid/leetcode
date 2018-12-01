if [ ! -f file.txt ]; then
    ln -s test/valid_phone_number.txt file.txt 
fi
#cat file.txt | egrep "{(\(\d+3\))(\d+3)-(\d+4)}|{(\d+3)-(\d+3)-(\d+4)}" #wrong 
#cat file.txt | egrep "\(\d{3}\)\d{3}-\d{4}|\d{3}-\d{3}-\d{4}"
#cat file.txt | egrep "(^\(\d{3}\)\d{3}-\d{4}$)|(^\d{3}-\d{3}-\d{4}$)"
cat file.txt | egrep "(^\([0-9]{3}\))([]?)[0-9]{3}-[0-9]{4}$)|(^[0-9]{3}-[0-9]{3}-[0-9]{4}$)"
#cat file.txt | egrep "(\d{3})(\-)(\d{3})(\-)"
#cat file.txt | egrep "(\d{3}-\d{3}-\d{4})|()"
