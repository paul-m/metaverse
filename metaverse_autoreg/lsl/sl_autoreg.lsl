key gRequest;

default
{
    touch_start(integer total_number)
    {
        if (llDetectedKey(0) == llGetOwner())
        {
            gRequest = llHTTPRequest("http://SOMEDOMAIN.COMMIE/inworld",
                            [HTTP_METHOD, "POST",
                            HTTP_MIMETYPE, "application/x-www-form-urlencoded"],
                            "app=metaverse_autoreg" +
                            "&cmd=autoregister" +
                            "&output_type=message" +
                            "&arg=" + 
                            "password=changethis:" +
                            "user_key=" + (string)llDetectedKey(0) + ":" +
                            "website_username=" + llDetectedName(0) + ":" +
                            "sl_username=" + llDetectedName(0) + ":" +
                            "verified_inworld=0"
                            );
        }
    }
    
    http_response(key request_id, integer status, list metadata, string body)
    {
        if (request_id == gRequest)
        {
            llOwnerSay("Status: " + (string)status + "\n" + body);
        }
    }
}
