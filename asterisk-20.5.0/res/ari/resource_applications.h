/*
 * Asterisk -- An open source telephony toolkit.
 *
 * Copyright (C) 2013, Digium, Inc.
 *
 * David M. Lee, II <dlee@digium.com>
 *
 * See http://www.asterisk.org for more information about
 * the Asterisk project. Please do not directly contact
 * any of the maintainers of this project for assistance;
 * the project provides a web site, mailing lists and IRC
 * channels for your use.
 *
 * This program is free software, distributed under the terms of
 * the GNU General Public License Version 2. See the LICENSE file
 * at the top of the source tree.
 */

/*! \file
 *
 * \brief Generated file - declares stubs to be implemented in
 * res/ari/resource_applications.c
 *
 * Stasis application resources
 *
 * \author David M. Lee, II <dlee@digium.com>
 */

/*
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * !!!!!                               DO NOT EDIT                        !!!!!
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * This file is generated by a mustache template. Please see the original
 * template in rest-api-templates/ari_resource.h.mustache
 */

#ifndef _ASTERISK_RESOURCE_APPLICATIONS_H
#define _ASTERISK_RESOURCE_APPLICATIONS_H

#include "asterisk/ari.h"

/*! Argument struct for ast_ari_applications_list() */
struct ast_ari_applications_list_args {
};
/*!
 * \brief List all applications.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_applications_list(struct ast_variable *headers, struct ast_ari_applications_list_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_applications_get() */
struct ast_ari_applications_get_args {
	/*! Application's name */
	const char *application_name;
};
/*!
 * \brief Get details of an application.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_applications_get(struct ast_variable *headers, struct ast_ari_applications_get_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_applications_subscribe() */
struct ast_ari_applications_subscribe_args {
	/*! Application's name */
	const char *application_name;
	/*! Array of URI for event source (channel:{channelId}, bridge:{bridgeId}, endpoint:{tech}[/{resource}], deviceState:{deviceName} */
	const char **event_source;
	/*! Length of event_source array. */
	size_t event_source_count;
	/*! Parsing context for event_source. */
	char *event_source_parse;
};
/*!
 * \brief Body parsing function for /applications/{applicationName}/subscription.
 * \param body The JSON body from which to parse parameters.
 * \param[out] args The args structure to parse into.
 * \retval zero on success
 * \retval non-zero on failure
 */
int ast_ari_applications_subscribe_parse_body(
	struct ast_json *body,
	struct ast_ari_applications_subscribe_args *args);

/*!
 * \brief Subscribe an application to a event source.
 *
 * Returns the state of the application after the subscriptions have changed
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_applications_subscribe(struct ast_variable *headers, struct ast_ari_applications_subscribe_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_applications_unsubscribe() */
struct ast_ari_applications_unsubscribe_args {
	/*! Application's name */
	const char *application_name;
	/*! Array of URI for event source (channel:{channelId}, bridge:{bridgeId}, endpoint:{tech}[/{resource}], deviceState:{deviceName} */
	const char **event_source;
	/*! Length of event_source array. */
	size_t event_source_count;
	/*! Parsing context for event_source. */
	char *event_source_parse;
};
/*!
 * \brief Body parsing function for /applications/{applicationName}/subscription.
 * \param body The JSON body from which to parse parameters.
 * \param[out] args The args structure to parse into.
 * \retval zero on success
 * \retval non-zero on failure
 */
int ast_ari_applications_unsubscribe_parse_body(
	struct ast_json *body,
	struct ast_ari_applications_unsubscribe_args *args);

/*!
 * \brief Unsubscribe an application from an event source.
 *
 * Returns the state of the application after the subscriptions have changed
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_applications_unsubscribe(struct ast_variable *headers, struct ast_ari_applications_unsubscribe_args *args, struct ast_ari_response *response);
/*! Argument struct for ast_ari_applications_filter() */
struct ast_ari_applications_filter_args {
	/*! Application's name */
	const char *application_name;
	/*! Specify which event types to allow/disallow */
	struct ast_json *filter;
};
/*!
 * \brief Body parsing function for /applications/{applicationName}/eventFilter.
 * \param body The JSON body from which to parse parameters.
 * \param[out] args The args structure to parse into.
 * \retval zero on success
 * \retval non-zero on failure
 */
int ast_ari_applications_filter_parse_body(
	struct ast_json *body,
	struct ast_ari_applications_filter_args *args);

/*!
 * \brief Filter application events types.
 *
 * Allowed and/or disallowed event type filtering can be done. The body (parameter) should specify a JSON key/value object that describes the type of event filtering needed. One, or both of the following keys can be designated:<br /><br />"allowed" - Specifies an allowed list of event types<br />"disallowed" - Specifies a disallowed list of event types<br /><br />Further, each of those key's value should be a JSON array that holds zero, or more JSON key/value objects. Each of these objects must contain the following key with an associated value:<br /><br />"type" - The type name of the event to filter<br /><br />The value must be the string name (case sensitive) of the event type that needs filtering. For example:<br /><br />{ "allowed": [ { "type": "StasisStart" }, { "type": "StasisEnd" } ] }<br /><br />As this specifies only an allowed list, then only those two event type messages are sent to the application. No other event messages are sent.<br /><br />The following rules apply:<br /><br />* If the body is empty, both the allowed and disallowed filters are set empty.<br />* If both list types are given then both are set to their respective values (note, specifying an empty array for a given type sets that type to empty).<br />* If only one list type is given then only that type is set. The other type is not updated.<br />* An empty "allowed" list means all events are allowed.<br />* An empty "disallowed" list means no events are disallowed.<br />* Disallowed events take precedence over allowed events if the event type is specified in both lists.
 *
 * \param headers HTTP headers
 * \param args Swagger parameters
 * \param[out] response HTTP response
 */
void ast_ari_applications_filter(struct ast_variable *headers, struct ast_ari_applications_filter_args *args, struct ast_ari_response *response);

#endif /* _ASTERISK_RESOURCE_APPLICATIONS_H */
