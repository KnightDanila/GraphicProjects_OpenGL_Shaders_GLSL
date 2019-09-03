/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
    Created on : 18.12.2017, 21:19:29
    Author     : KnightDanila
*/


var SimpleTimer = function () {
    var mainID = "",
            start = new Date().getTime();

    this.init = function (mainID) {
        this.start = new Date().getTime();
        this.mainID = mainID;
        //document.getElementById(this.mainID).className = 'simpleTimer';
        setInterval(
                this.showTime.bind(this) // this will run after every 1 seconds
                , 1000);
    };
    this.startAgain = function () {
        this.start = new Date().getTime();
    };
    this.getTime = function () {
        return (new Date().getTime()) - this.start;
    };
    this.showTime = function () { //https://www.youtube.com/watch?v=LUapZhcsdx8
        var date = new Date(this.getTime());
        var values = [date.getUTCHours(), date.getMinutes(), date.getSeconds()];

        for (var i = 0; i < 3; i++)
            if (values[i] < 10)
                values[i] = "0" + values[i];

        document.getElementById(this.mainID).innerHTML = values.join(":");
    };
};