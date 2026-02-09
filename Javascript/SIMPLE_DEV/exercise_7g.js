function convertLength(length,from,to){
    let result;
    if(from==='km' && to==='miles'){
        result=length / 1.6 + ' miles';
    }
    else if(from==='km' && to==='ft'){
        result=length * 3281 + ' ft';
    }
    else if(from==='miles' && to==='km'){
        result=length * 1.6 + ' km';
    }
    else if(from==='miles' && to==='ft'){
        result=length * 5280 + ' ft';
    }
    else if(from==='ft' && to==='km'){
        result=length /3281 + ' km';
    }
    else if(from==='ft' && to==='miles'){
        result=length /5280 + ' miles';
    }
    else if(from===to){
        result=length + ' ' + to;
    }
    else{
        result=`Invalid unit:${from}`;
    }
    return result;
}
console.log(convertLength(32,'km','miles'));
console.log(convertLength(50,'km','ft'));
console.log(convertLength(50,'miles','km'));
console.log(convertLength(5,'ft','km'));
console.log(convertLength(5,'ft','miles'));
console.log(convertLength(5,'lbs','km'));