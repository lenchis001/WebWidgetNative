document.addEventListener('DOMContentLoaded', function(){
	start();
});

function start() {
   try {
        tizen.application.getAppsContext(onGetAppsContextSuccess,
            onGetAppsContextError);
    } catch (e) {
        alert('Get AppContext Error: ' + e.message);
    }
}

function onGetAppsContextSuccess(contexts) {
	document.getElementById("list_of_services").innerHTML = 
		contexts.reduce(function (a, b) { return a + ", " + b.appId; }, "");
}

function onGetAppsContextError(err) {
    alert('getAppsContext exc' + err);
}
