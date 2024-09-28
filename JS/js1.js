function x()
{
    const a=0;
    console.log("Ok");
    function y()
    {
        console.log("Hello WOrld");
    }
    return y;
}
var z=x();
console.log(z);